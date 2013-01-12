#include "argParser.hpp"

#include <sstream>

const std::string Options::template_dir = TEMPLATE_DIR; // This will be expanded from -DTEMPLATE_DIR=... check cmake vars...
std::string Options::_defaultHost = "localhost";
std::string Options::_defaultPort = "5432"; // Postgres default

////////////////////////////////////////////////////////////////////////////////
#ifdef DB_SQLITE
////////////////////////////////////////////////////////////////////////////////

const char* BadOptionsError::helpMessage = R"(Please enter the options in order. Only baseName is required, all others can be guessed by the program: baseName exeName dbName)";

std::string Options::dbInitString() const {
    return dbName() + ".db";
}

////////////////////////////////////////////////////////////////////////////////
#elif defined DB_POSTGRES 
////////////////////////////////////////////////////////////////////////////////

const char* BadOptionsError::helpMessage = R"(Please enter the options in order. Only baseName is required, all others can be guessed by the program: baseName exeName dbName dbHost dbPort dbUser dbPassword)";

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
#else
#error You need to choose a supported DB type in ccmake. MySql is not supported yet. Please feel free to write it and submit a patch.
#endif
////////////////////////////////////////////////////////////////////////////////
