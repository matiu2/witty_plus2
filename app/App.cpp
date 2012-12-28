#include "App.hpp"

#include <Wt/WText>

namespace witty_plus {
namespace app {

App::App(const Wt::WEnvironment& env)
    : Wt::WApplication(env), _session(appRoot() + "auth.db")
{
    new Wt::WText("Hello world", root());
}

}
}
