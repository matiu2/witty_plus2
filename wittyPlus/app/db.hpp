#include <Wt/Dbo/SqlConnection>
#include <memory>

namespace witty_plus {
namespace app {

std::unique_ptr<Wt::Dbo::SqlConnection> makeConnection(const std::string& connection_string);

}
}
