/// Parses the command line arguments
#pragma once

#include <string>
#include <vector>
#include <stdexcept>


struct BadOptionsError : std::runtime_error {
    static const char* helpMessage;
    BadOptionsError() : std::runtime_error(BadOptionsError::helpMessage) {}
};

struct Options {
private:
    std::string _baseName;
    std::string _exeName;
    std::string _dbName;
    std::string _dbHost;
    std::string _dbPort;
    std::string _dbUser;
    std::string _dbPass;
    static std::string _defaultHost;
    static std::string _defaultPort;
    static std::string _dbWtLibName;
public:
    static const std::string template_dir;

    Options(int argc, const char** argv) {
        if (argc <= 1)
            printUsageAndExit();
        // Copy argv into our variables in order they are declared..
        std::vector<std::string> input(argv, argv+argc);
        const std::vector<std::string*> options {
            &_baseName,
            &_exeName,
            &_dbName,
            &_dbHost,
            &_dbPort,
            &_dbUser,
            &_dbPass
        };
        auto i = input.begin()+1; // +1 because 0 is the program name
        auto end = i + std::min(input.size()-1, options.size());
        auto option = options.begin();
        while (i != end)
            **option++ = *i++;
    }

    void printUsageAndExit() {
        throw BadOptionsError();
    }

    std::string dbInitString() const;
    const std::string& templateDir() const { return Options::template_dir; }
    const std::string& baseName() const { return _baseName; }
    const std::string& exeName() const { return !_exeName.empty() ? _exeName : _baseName; }
    const std::string& dbName() const { return !_dbName.empty() ? _dbName : _baseName; }
    const std::string& dbHost() const { return !_dbHost.empty() ? _dbHost : _defaultHost; }
    const std::string& dbPort() const { return !_dbPort.empty() ? _dbPort : _defaultPort; }
    const std::string& dbUser() const { return !_dbUser.empty() ? _dbUser : _baseName; }
    const std::string& dbPass() const { return !_dbPass.empty() ? _dbPass : _baseName; }
    const std::string& dbWtLibName() const { return _dbWtLibName; }
};
