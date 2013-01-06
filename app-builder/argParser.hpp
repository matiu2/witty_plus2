/// Parses the command line arguments
#pragma once
#include <string>
#include <vector>
#include <stdexcept>


struct Options {
    std::string baseName;
    std::string exeName;
    std::string dbName;
    std::string dbHost;
    std::string dbPort;
    std::string dbUser;
    std::string dbPass;

    static const char* helpMessage;

    Options(int argc, const char** argv) {
        if (argc <= 1)
            printUsageAndExit();
        std::vector<std::string> input(argv, argv+argc);
        const std::vector<std::string*> options {
            &baseName,
            &exeName,
            &dbName,
            &dbHost,
            &dbPort,
            &dbUser,
            &dbPass
        };
        auto i = input.begin()+1; // +1 because 0 is the program name
        auto end = i + std::min(input.size()-1, options.size());
        auto option = options.begin();
        while (i != end)
            **option++ = *i++;
    }

    void printUsageAndExit() {
        throw std::runtime_error(Options::helpMessage);
    }

    std::string dbInitString() const;

};
