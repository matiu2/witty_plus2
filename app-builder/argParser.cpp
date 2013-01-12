#include "argParser.hpp"

#include <sstream>

const std::string Options::template_dir = TEMPLATE_DIR; // This will be expanded from -DTEMPLATE_DIR=... check cmake vars...

#ifdef DB_SQLITE
////////////////////////////////////////////////////////////////////////////////

const char* BadOptionsError::helpMessage = R"(Please enter the options in order. Only baseName is required, all others can be guessed by the program: baseName exeName dbName)";

std::string Options::dbInitString() const {
    std::stringstream ss;
    ss << "host=" << dbHost() << ' '
       << "port=" << dbPort() << ' '
       << "dbname=" << dbName() << ' '
       << "user=" << dbUser() << ' '
       << "password=" << dbPass();
    return ss.str();
}

////////////////////////////////////////////////////////////////////////////////
#elif defined DB_POSTGRES 
////////////////////////////////////////////////////////////////////////////////

const char* BadOptionsError::helpMessage = R"(Please enter the options in order. Only baseName is required, all others can be guessed by the program: baseName exeName dbName dbHost dbPort dbUser dbPassword)";

std::string Options::dbInitString() {
    return dbName() + ".db";
}

////////////////////////////////////////////////////////////////////////////////
#else
#error You need to choose a supported DB type in ccmake. MySql is not supported yet. Please feel free to write it and submit a patch.
#endif
////////////////////////////////////////////////////////////////////////////////
