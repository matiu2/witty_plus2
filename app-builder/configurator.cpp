#include "configurator.hpp"

#include <algorithm>
#include <string>
#include <sstream>
#include <fstream>
#include <iterator>
#include <boost/iostreams/device/mapped_file.hpp>
#include <regex>

/** Reads in a file template and outputs it in the build dir.
    It searches for variables surrounded by two triangle brackets, eg. <<some_var>>
    And replaces those with the variable values
**/
void configureCMakeTemplateFiles(
    const Options& opt,
    const std::string& inFileName,
    const std::string& outFileName)
{
    boost::iostreams::mapped_file_source inf;
    try {
        inf.open(inFileName);
    } catch (std::ios_base::failure e) {
        std::stringstream msg;
        msg << "Couldn't read file to configure: \""
            << inFileName << '"'
            << " Error message: "
            << e.what();
        throw std::ios_base::failure(msg.str());
    }
    const char* in(inf.data());
    const char* inEnd(in+inf.size());
    std::ofstream outf(outFileName);
    std::ostream_iterator<char> out(outf);

    // Easier find function, throws HitEnd if we hit the end of the stream
    struct HitEnd{};
    auto findTwo = [&inEnd](const char* start, char delim) {
        for (;;) {
            auto result = std::find(start, inEnd, delim);
            if (result >= inEnd-1)
                throw HitEnd();
            // If the second deliminator is not there, it's a false alarm
            if (result[1] != delim)
                continue;
            return result;
        }
    };

    for (;;) {
        // Looking for <<SOMETHING>>
        try {
            // Find the delimeters "<<" and ">>"
            auto delimStart = findTwo(in, '<');
            auto delimEnd = findTwo(delimStart+2, '>');
            // Copy the file up to the start of the delimeter
            outf.write(in, delimStart-in);
            // Get the name
            std::string propertyName;
            propertyName.reserve(delimEnd-delimStart-2);
            std::transform(delimStart+2, delimEnd, std::back_inserter(propertyName), ::tolower);
            // Write out the value
            if (propertyName ==  "project_name")
                outf << opt.baseName();
            else if (propertyName == "db_init_string")
                outf << opt.dbInitString();
            else if (propertyName == "executable_name")
                outf << opt.exeName();
            else if (propertyName == "db_wt_lib_name")
                outf << opt.dbWtLibName();
            else {
                std::stringstream msg;
                msg << "Found an unrecognized property name: '" << propertyName
                    << "' in file '" << inFileName << "'";
                throw std::runtime_error(msg.str());
            }
            in = delimEnd+2;
        } catch (HitEnd) {
            break;
        }
    }
    // Copy the last bit of file
    std::copy(in, inEnd, out);
}
