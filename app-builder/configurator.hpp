/// Configurates the build files for the new app

#include "argParser.hpp"
#include <string>

namespace boost {
    namespace iostreams {
    class mapped_file_source;
    }
}

struct Configurator {
    const Options& options;
    static const std::string install_dir;
    Configurator(const Options& aOptions);
};
