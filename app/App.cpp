#include "App.hpp"

#include <Wt/WText>

namespace app {

App::App(const Wt::WEnvironment& env) : Wt::WApplication(env) {
    new Wt::WText("Hello world", root());
}

}
