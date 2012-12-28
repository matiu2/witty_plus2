#include "Server.hpp"
#include <Wt/Auth/GoogleService>
#include <Wt/Auth/FacebookService>

namespace witty_plus {
namespace app {

Server::Server(const std::string &wtApplicationPath, const std::string &wtConfigurationFile)
    : Wt::WServer(wtApplicationPath, wtConfigurationFile), _passwordService(_authService)
{
    configureAuth();
}

void Server::configureAuth()
{
    // TODO: Allow library user or config to specify the cookie name
    _authService.setAuthTokensEnabled(true, "witty_plus_cookie");
    _authService.setEmailVerificationEnabled(true);

    Wt::Auth::PasswordVerifier *verifier = new Wt::Auth::PasswordVerifier();
    verifier->addHashFunction(new Wt::Auth::BCryptHashFunction(12));
    _passwordService.setVerifier(verifier);
    _passwordService.setAttemptThrottlingEnabled(true);
    _passwordService.setStrengthValidator(new Wt::Auth::PasswordStrengthValidator());

    if (Wt::Auth::GoogleService::configured())
        _oAuthServices.push_back(new Wt::Auth::GoogleService(_authService));
    if (Wt::Auth::FacebookService::configured())
        _oAuthServices.push_back(new Wt::Auth::FacebookService(_authService));
}

}
}
