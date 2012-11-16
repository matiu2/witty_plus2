/// This is the server .. there is only one of these in the whole process
#include <Wt/WServer>

namespace app {

class Server : public Wt::WServer {
private:
public:
    Server(
        const std::string &wtApplicationPath=std::string(),
        const std::string &wtConfigurationFile=std::string()
    );
};

}
