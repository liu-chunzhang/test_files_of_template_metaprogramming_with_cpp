#include <format>
#include <iostream>
#include <numeric>
#include <ranges>
#include <sstream>
#include <vector>

int main(){
    auto text = "19.99 7.50 49.19 20 12.34";
    auto stream = std::istringstream{ text };
    std::vector<double> prices;
    for (double const price : std::ranges::istream_view<double>(stream))
    {
        prices.push_back(price);
    }
    auto total = std::accumulate(prices.begin(), prices.end(), 0.0);
    std::cout << std::format("total: {}\n", total);
    return 0;
}