

class MoonCake():
    def __init__(self, inventory_amount, price):
        self.inventory_amount = inventory_amount
        self.price = price
        self.price_per_amout = price / inventory_amount

    def __lt__(self, other):
        return self.price_per_amout < other.price_per_amout


def maximum_profit(mooncakes, total_demand):
    profit = 0
    amount_cnt = 0
    mooncakes = sorted(mooncakes, reverse=True)
    for cake in mooncakes:
        take = min(total_demand - amount_cnt, cake.inventory_amount)
        if take == 0:
            break
        amount_cnt += take
        profit += take * cake.price_per_amout
    return profit


if __name__ == '__main__':
    _, total_demand = [float(i) for i in input().split()]
    mooncakes = []
    for inventory_amount, price in zip(input().split(), input().split()):
        mooncakes.append(MoonCake(float(inventory_amount), float(price)))
    profit = maximum_profit(mooncakes, total_demand)
    print(f'{profit:.2f}')
