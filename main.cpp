#include "app/Server.hpp"
#include "app/App.hpp"
#include <signal.h>
#include <Wt/WConfig.h>

int main(int argc, char** argv) {
    app::Server server(argv[0]);
    server.setServerConfiguration(argc, argv, WTHTTP_CONFIGURATION);
    server.addEntryPoint(Wt::Application,
                         [](const Wt::WEnvironment& env){ return new HelloApp(env); });
    if (server.start()) {
        int sig = Wt::WServer::waitForShutdown(argv[0]);
        std::cerr << "Shutdown (signal = " << sig << ")" << std::endl;
        server.stop();
        if (sig == SIGHUP)
            Wt::WServer::restart(argc, argv, environ);
    }
    return 0;
}
