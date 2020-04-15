# idea:
# (`max_dist` is the maximum distance that the current station can reach)
# 1. find the next cheaper station within `max_dist` as the `next_station`
# 2. if there is no such station, choose the station just before the `max_dist`
#    as the `next_station` (i.e. the most closest to `max_dist`)

from collections import namedtuple


Station = namedtuple('Station', ['price', 'dist'])


def route(capacity, dst_dist, dist_per_unit, stations):
    stations.sort(key=lambda x: x.dist)
    max_dist, curr_station = 0, 0
    total_price = 0.
    traveled_dist = 0
    if stations[0].dist != 0:
        print(f'The maximum travel distance = 0.00')
        return
    while True:
        curr_price, curr_dist = stations[curr_station]
        max_dist = curr_dist + capacity * dist_per_unit
        next_station = curr_station + 1
        while (next_station < len(stations) and
               stations[next_station].dist <= max_dist):
            # find the next cheaper station as `next_station`
            if stations[next_station].price < curr_price:
                total_price += (stations[next_station].dist -
                                traveled_dist) / dist_per_unit * curr_price
                traveled_dist = stations[next_station].dist
                break
            next_station += 1
        else:
            if next_station == len(stations):
                if max_dist >= dst_dist:
                    total_price += (dst_dist -
                                    traveled_dist) / dist_per_unit * curr_price
                    print(f'{total_price:.2f}')
                else:
                    print(f'The maximum travel distance = {max_dist:.2f}')
                break
            # using the station closest to `max_dist` as `next_station`
            next_station -= 1  # the most closest to max_dist
            total_price += (max_dist -
                            traveled_dist) / dist_per_unit * curr_price
            traveled_dist = max_dist
        curr_station = next_station


if __name__ == '__main__':
    capacity, dst_dist, dist_per_unit, n_station = [
        int(i) for i in input().split()]
    stations = []
    for _ in range(n_station):
        gas_price, dist = input().split()
        stations.append(Station(float(gas_price), int(dist)))
    route(capacity, dst_dist, dist_per_unit, stations)
