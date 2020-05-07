#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iomanip>


struct MoonCake {
    // constructor
    MoonCake(double inventory_amount, double price):
        inventory_amount(inventory_amount), price(price),
        price_per_amout(price / inventory_amount) {};
    // member
    double inventory_amount;
    double price, price_per_amout;
};


bool comp(const MoonCake &m1, const MoonCake &m2) {
    return m1.price_per_amout < m2.price_per_amout;
}


double maximum_profit(std::vector<MoonCake> mooncakes, int total_demand) {
    std::sort(mooncakes.rbegin(), mooncakes.rend(), comp);
    double profit = 0.;
    double amount_cnt = 0.;
    for (MoonCake &cake : mooncakes) {
        int take = std::min(total_demand - amount_cnt, cake.inventory_amount);
        if (take == 0) break;
        amount_cnt += take;
        profit += take * cake.price_per_amout;
    }
    return profit;
}


int main() {

    int n_caketype;
    double total_demand;
    std::cin >> n_caketype >> total_demand;
    std::cin.ignore(1, '\n');

    std::string line;
    std::getline(std::cin, line);
    std::istringstream amount_stm(line);
    std::getline(std::cin, line);
    std::istringstream price_stm(line);

    std::vector<MoonCake> mooncakes;
    while (n_caketype--) {
        double inventory_amount, price;
        amount_stm >> inventory_amount;
        price_stm >> price;
        mooncakes.push_back(MoonCake(inventory_amount, price));
    }

    double profit = maximum_profit(mooncakes, total_demand);
    std::cout << std::fixed << std::setprecision(2)
              << profit << '\n'
              << std::defaultfloat;

    return 0;
}
