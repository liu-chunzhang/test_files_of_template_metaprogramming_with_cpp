#include <map>
#include <vector>

template <typename T>
using customer_addresses_t = std::map<int, std::vector<T>>;

struct delivery_address_t {};
struct invoice_address_t {};

using customer_delivery_addresses_t = customer_addresses_t<delivery_address_t>;
using customer_invoice_addresses_t = customer_addresses_t<invoice_address_t>;


int main(){

    return 0;
}