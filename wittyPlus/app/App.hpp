#pragma once

#include <memory>
#include <Wt/WApplication>
#include "UserSession.hpp"

namespace witty_plus {
namespace app {

    class App : public Wt::WApplication {
    public:
        typedef <std::unique_ptr<Wt::Dbo::SqlConnection>(const string&)> GetConnFunc;
    private:
        UserSession _userSession;
        std::string getDBConnectionString(app) {
            std::string result;
            app->readConfigurationProperty("db_connection_string", result);
            return result;
        }
    public:
        App(const Wt::WEnvironment& env, GetConnFunc getConn);
}
}
