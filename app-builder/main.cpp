/// Will slightly customize and build you a beautiful app source tree based on app-template

#include "argParser.hpp"
#include "configurator.hpp"

#include <boost/filesystem.hpp>

#include <iostream>

int main(int argc, const char** argv) {
    namespace fs = boost::filesystem;
    try {
        // Load the options
        Options opt(argc, argv);
        // Copy over the app-template directory
        fs::path absDest;
        try {
            absDest = fs::absolute(fs::current_path() / opt.baseName());
        } catch (fs::filesystem_error e) {
            std::cerr << "Couldn't get the current directory. Perhaps we're working in a deleted dir ? "
                      << "maybe retry after: cd .."
                      << std::endl;
            exit(-1);
        }
        std::string absSource = fs::absolute(opt.templateDir()).native();
        fs::path absd = fs::absolute(opt.templateDir());
        std::cout << "Copying template dir from "
                  << absSource << " to "
                  << absDest << " ..." << std::endl;
        std::string src;
        std::string dest;
        try {
            fs::create_directories(absDest);
            auto path = fs::recursive_directory_iterator(opt.templateDir());
            auto end = fs::recursive_directory_iterator();
            while (path != end) {
                // Work out what we're copying
                src = fs::absolute(*path++).native();
                dest = absDest.native();
                dest += src.substr(absSource.length());
                fs::copy(src, dest);
            }
        } catch (fs::filesystem_error e) {
            std::cerr << "Unable to copy directories:" << std::endl
                      << "  Source: " << src << std::endl
                      << "  Dest: " << dest << std::endl
                      << "  Reason: " << e.what() << std::endl;
            exit(-2);
        }
        std::cout << "Customizing cmake file.." << std::endl;
        // Write the defaule cmake files and wt-config file
        configureCMakeTemplateFiles(opt,
                                    opt.templateDir() + "/CMakeLists.txt",
                                    opt.baseName() + "/CMakeLists.txt");
        configureCMakeTemplateFiles(opt,
                                    opt.templateDir() + "/cmake/settings.cmake",
                                    opt.baseName() + "/cmake/settings.cmake");
        std::cout << "Done." << std::endl;
    } catch (std::runtime_error e) {
        std::cout << e.what() << std::endl;
        return 1;
    }
}
