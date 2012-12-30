/// This is the server .. there is only one of these in the whole process
#include <Wt/WServer>

#include <Wt/Auth/AuthService>
#include <Wt/Auth/HashFunction>
#include <Wt/Auth/PasswordService>
#include <Wt/Auth/PasswordStrengthValidator>
#include <Wt/Auth/PasswordVerifier>
#include <Wt/Auth/GoogleService>

namespace witty_plus {
namespace app {

void initServerInstance();

class Server : public Wt::WServer {
private:
    static Server* _instance;
    Wt::Auth::AuthService _authService;
    Wt::Auth::PasswordService _passwordService;
    std::vector< const Wt::Auth::OAuthService *> _oAuthServices;
    void configureAuth();
public:
    Server(
        const std::string &wtApplicationPath=std::string(),
        const std::string &wtConfigurationFile=std::string()
    );
    const Wt::Auth::AuthService& authService() { return _authService; }
    const Wt::Auth::PasswordService& passwordService() { return _passwordService; }
    const std::vector< const Wt::Auth::OAuthService *>& oAuthServices() { return _oAuthServices; }
    static Server* instance() { return _instance; }
};

}
}
