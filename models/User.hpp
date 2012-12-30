#ifndef USER_HPP
#define USER_HPP

#include <Wt/Dbo/Dbo>
#include <Wt/WGlobal>
#include <Wt/Auth/Dbo/UserDatabase>

namespace witty_plus {
namespace models {

class User;
typedef Wt::Auth::Dbo::AuthInfo<User> AuthInfo;
typedef Wt::Auth::Dbo::UserDatabase<AuthInfo> UserDatabase;

class User : public Wt::Dbo::Dbo<User> {
public:
    template<class Action>
    void persist(Action&) {
    }
};


}
}

namespace Wt {
namespace Dbo {
DBO_EXTERN_TEMPLATES(witty_plus::models::User);
}
}

#endif // USER_HPP
