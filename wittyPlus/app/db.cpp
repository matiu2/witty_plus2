#include "db.hpp"

#ifdef DB_SQLITE
#include <Wt/Dbo/backend/Sqlite3>
#elif defined DB_POSTGRES 
#include <Wt/Dbo/backend/Postgres>
#else
#error You need to choose a supported DB type in ccmake
#endif

namespace witty_plus {
namespace app {

std::unique_ptr<Wt::Dbo::SqlConnection> makeConnection(const std::string& connection_string) {
    #ifdef DB_SQLITE
    return std::unique_ptr<Wt::Dbo::SqlConnection>(new Wt::Dbo::backend::Sqlite3(connection_string));
    #elif defined DB_POSTGRES 
    return std::unique_ptr<Wt::Dbo::SqlConnection>(new Wt::Dbo::backend::Postgres(connection_string));
    #else
    #error You need to choose a supported DB type in ccmake
    return nullptr;
    #endif
}

}
}
