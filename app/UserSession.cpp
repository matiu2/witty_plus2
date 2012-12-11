#include "UserSession.hpp"

#include <Wt/Auth/Dbo/AuthInfo>
#include <Wt/Auth/Dbo/UserDatabase>

namespace witty_plus {
namespace app {

UserSession::UserSession(const std::string& dbConnectionString)
    : _connection(dbConnectionString)
{
    setConnection(_connection);

    mapClass<models::User>("user");
    mapClass<models::AuthInfo>("auth_info");
    mapClass<models::AuthInfo::AuthIdentityType>("auth_identity");
    mapClass<models::AuthInfo::AuthTokenType>("auth_token");

    try {
        createTables();
        std::cerr << "Created database." << std::endl;
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
        std::cerr << "Using existing database";
    }

    _users = new UserDatabase(*this);
}

} // namespace app
} // namespace witty_plus
