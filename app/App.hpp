#pragma once

#include <Wt/WApplication>

namespace witty_plus {
namespace app {

    class App : public Wt::WApplication {
    private:
    public:
        App(const Wt::WEnvironment& env);
    };

}
}
