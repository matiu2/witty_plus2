#include "Server.hpp"

namespace app {

Server::Server(const std::string &wtApplicationPath, const std::string &wtConfigurationFile) :
    Wt::WServer(wtApplicationPath, wtConfigurationFile) {
}

}
