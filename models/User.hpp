#ifndef USER_HPP
#define USER_HPP

#include <Wt/Dbo/Dbo>
#include <Wt/WGlobal>

namespace witty_plus {
namespace models {

class User : public Dbo::Dbo {
public:
    User();
    template<class Action>
    void persist(Action& a)
    {
    }
};

}
}

#endif // USER_HPP
