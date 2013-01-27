#include <Wt/Dbo/SqlConnection>
#include <memory>

namespace witty_plus {
namespace app {

template<typename T>
std::unique_ptr<Wt::Dbo::SqlConnection> makeConnection(const std::string& connection_string) {
    std::static_assert<std::is_base_of<Wt::Dbo::SqlConnection, T>>;
    return std::unique_ptr<Wt::Dbo::SqlConnection>(new T(connection_string));
}
