#ifndef WITTY_PLUS_APP_USERSESSION_HPP
#define WITTY_PLUS_APP_USERSESSION_HPP

#include <string>

#include <Wt/Dbo/Session>
#include <Wt/Dbo/ptr>
#include <Wt/Auth/Login>


#include "db.hpp"
#include "../models/User.hpp"

namespace witty_plus {
namespace app {

class UserSession : public Wt::Dbo::Session {
public:
    typedef Wt::Auth::Dbo::UserDatabase<models::AuthInfo> UserDatabase;
private:
    std::unique_ptr<Wt::Dbo::SqlConnection> _connection;
    models::UserDatabase *_users;
    Wt::Auth::Login _login;
public:
    UserSession(const std::string& dbConnectionString);

    Wt::Auth::AbstractUserDatabase& users();
    Wt::Auth::Login& login() { return _login; }
};

} // namespace app
} // namespace witty_plus

#endif // WITTY_PLUS_APP_USERSESSION_HPP
