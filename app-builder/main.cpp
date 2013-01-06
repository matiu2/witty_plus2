/// Will slightly customize and build you a beautiful app source tree based on app-template

#include "argParser.hpp"
#include "configurator.hpp"

#include <iostream>

int main(int argc, const char** argv) {
    try {
        Options opt(argc, argv);
        Configurator c(opt);
    } catch (std::runtime_error e) {
        std::cout << e.what() << std::endl;
        return 1;
    }
}
