

class Billionaire():
    def __init__(self, name, age, net_worth):
        self.name = name
        self.age = age
        self.net_worth = net_worth

    def __lt__(self, other):
        if self.net_worth > other.net_worth:
            return True
        elif self.net_worth < other.net_worth:
            return False
        # if net_worth are equal
        if self.age < other.age:
            return True
        elif self.age > other.age:
            return False
        # if net_worth & age are equal
        return self.name < other.name

    def __str__(self):
        return f'{self.name} {self.age} {self.net_worth}'


if __name__ == '__main__':
    n_billionare, n_query = [int(i) for i in input().split()]
    database = []
    for _ in range(n_billionare):
        name, age, net_worth = input().split()
        database.append(Billionaire(name, int(age), int(net_worth)))
    database.sort()
    queries = []
    for i in range(1, n_query + 1):
        max_output, a_min, a_max = [int(i) for i in input().split()]
        count = 0
        print(f'Case #{i}:')
        for billionaire in database:
            if a_min <= billionaire.age <= a_max:
                print(billionaire)
                count += 1
            if count >= max_output:
                break
        if count == 0:
            print("None")
