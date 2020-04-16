#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>


struct Station {
    double price, dist;
};


void
cheapest_route(double capacity, double dst_dist, double dist_per_unit,
               std::vector<Station> &stations)
{
    std::sort(stations.begin(), stations.end(),
              [](const Station &s1, const Station &s2)
                {return s1.dist < s2.dist;});
    std::size_t curr_station = 0;
    double traveled_dist = 0, total_price = 0.;
    if (stations.front().dist != 0) {
        std::cout << "The maximum travel distance = 0.00" << '\n';
        return;
    }
    while (true) {
        double curr_price = stations[curr_station].price;
        double curr_dist = stations[curr_station].dist;
        double max_dist = curr_dist + capacity * dist_per_unit;
        std::size_t next_station = curr_station + 1;
        while (next_station < stations.size() &&
               stations[next_station].dist <= max_dist) {
            // find the next cheaper station as `next_station`
            if (stations[next_station].price < curr_price) {
                total_price += (stations[next_station].dist -
                                traveled_dist) / dist_per_unit * curr_price;
                traveled_dist = stations[next_station].dist;
                break;
            }
            ++next_station;
        }
        // if there is no cheaper station,
        // using the station closest to `max_dist` as `next_station`
        if (next_station < stations.size() &&
            stations[next_station].dist > max_dist) {
            --next_station;
            total_price += (max_dist -
                            traveled_dist) / dist_per_unit * curr_price;
            traveled_dist = max_dist;
        }
        if (next_station == stations.size()) {
            if (max_dist >= dst_dist) {
                total_price += (dst_dist -
                                traveled_dist) / dist_per_unit * curr_price;
                std::cout << total_price << '\n';
            } else {
                std::cout << "The maximum travel distance = "
                          << max_dist << '\n';
            }
            return;
        }
        curr_station = next_station;
    }
}


int main() {

    double capacity, dst_dist, dist_per_unit, n_station;
    std::cin >> capacity >> dst_dist >> dist_per_unit >> n_station;

    std::vector<Station> stations;
    while (n_station--) {
        double price, dist;
        std::cin >> price >> dist;
        stations.push_back({price, dist});
    }

    std::cout << std::fixed << std::setprecision(2);
    cheapest_route(capacity, dst_dist, dist_per_unit, stations);

    return 0;
}
