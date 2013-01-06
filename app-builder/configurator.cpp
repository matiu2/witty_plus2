#include "configurator.hpp"

#include <algorithm>
#include <string>
#include <sstream>
#include <fstream>
#include <iterator>
#include <boost/iostreams/device/mapped_file.hpp>
#include <regex>

const std::string Configurator::install_dir = TEMPLATE_DIR; // This will be expanded from -DTEMPLATE_DIR=... in compiler

/** Reads in a file template and outputs it in the build dir.
    It searches for variables surrounded by two triangle brackets, eg. <<some_var>>
    And replaces those with the variable values
**/
Configurator::Configurator(const Options& aOptions) : options(aOptions) {
    const std::string inFileName(install_dir + "/CMakeLists.txt");
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
    std::ofstream outf("CMakeLists.txt");
    std::ostream_iterator<char> out(outf);

    std::cmatch found;
    std::regex rx("<<(.*)(>>)");

    while (std::regex_search(in, inEnd, found, rx)) {
        // Copy from in to the start of the match
        const char* last = in + found.length();
        std::copy(in, last, out);
        in = last;
        // Read the property name from the template file into lower case
        std::string propertyName = found[0].str();
        std::transform(propertyName.begin(), propertyName.end(), propertyName.begin(), ::tolower);
        // Write out the value
        if (propertyName ==  "project_name")
            outf << options.baseName;
        else if (propertyName == "db_init_string")
            outf << options.dbInitString();
        else if (propertyName == "executable_name")
            outf << options.exeName;
        else {
            std::stringstream msg;
            msg << "Found an unrecognized property name: '" << propertyName
                << "' in file '" << inFileName << "'";
            throw std::runtime_error(msg.str());
        }
    }
    // Copy the last bit of file
    std::copy(in, inEnd, out);
}
