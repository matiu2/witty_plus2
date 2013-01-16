/// Configurates the build files for the new app

#pragma once

#include "argParser.hpp"
#include <string>

void configureCMakeTemplateFiles(
    const Options& opt,
    const std::string& inFileName,
    const std::string& outFileName);
