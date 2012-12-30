#pragma once

#include <Wt/WApplication>
#include "UserSession.hpp"

namespace witty_plus {
namespace app {

    class App : public Wt::WApplication {
    private:
        UserSession _userSession;
    public:
        App(const Wt::WEnvironment& env);
    };

}
}
