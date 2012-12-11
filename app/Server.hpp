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

class Server : public Wt::WServer {
private:
    Wt::Auth::AuthService _authService;
    Wt::Auth::PasswordService _passwordService;
    std::vector< const Wt::Auth::OAuthService *> _oAuthServices;
    void configureAuth();
public:
    Server(
        const std::string &wtApplicationPath=std::string(),
        const std::string &wtConfigurationFile=std::string()
    );
    const Wt::Auth::AuthService& auth() { return _auth; }
    const Wt::Auth::PasswordService& passwordAuth() { return _passwordService; }
    const std::vector< const Wt::Auth::OAuthService *>& oAuthServices() { return _oAuthServices; }
};

}
}
