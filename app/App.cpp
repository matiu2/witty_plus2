#include "App.hpp"
#include "Server.hpp"

#include <Wt/WText>
#include <Wt/Auth/AuthWidget>
#include <Wt/Auth/RegistrationWidget>

namespace witty_plus {
namespace app {

App::App(const Wt::WEnvironment& env)
    : Wt::WApplication(env), _userSession(appRoot() + "auth.db")
{
    new Wt::WText("<h1>Auth Widget</h1>", root());
    Server* s(Server::instance());
    auto auth = new Wt::Auth::AuthWidget(s->authService(), _userSession.users(), _userSession.login(), root());
    auth->processEnvironment();
    auth->setRegistrationEnabled(true);
    auth->model()->addPasswordAuth(&s->passwordService());
    auth->model()->addOAuth(s->oAuthServices());
}

}
}
