#include "argParser.hpp"

#include <sstream>


#ifdef DB_SQLITE

const char* Options::helpMessage = R"(Please enter the options in order. Only baseName is required, all others can be guessed by the program: baseName exeName dbName)";

std::string Options::dbInitString() const {
    std::stringstream ss;
    ss << "host=" << dbHost << ' '
       << "port=" << dbPort << ' '
       << "dbname=" << dbName << ' '
       << "user=" << dbUser << ' '
       << "password=" << dbPass;
    return ss.str();
}

#elif defined DB_POSTGRES 

const char* Options::helpMessage = R"(Please enter the options in order. Only baseName is required, all others can be guessed by the program: baseName exeName dbName dbHost dbPort dbUser dbPassword)";

std::string Options::dbInitString() {
    return dbName + ".db";
}

#else
#error You need to choose a supported DB type in ccmake
#endif
