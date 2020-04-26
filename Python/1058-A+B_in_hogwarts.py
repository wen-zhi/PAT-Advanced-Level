

class Money():
    def __init__(self, galleon, sickle, knut):
        self.galleon = galleon
        self.sickle = sickle
        self.knut = knut
        self.knuts = ((galleon * 17 + sickle) * 29) + knut

    def __add__(self, other):
        knuts = self.knuts + other.knuts
        temp, knut = divmod(knuts, 29)
        galleon, sickle = divmod(temp, 17)
        return Money(galleon, sickle, knut)

    def __str__(self):
        return f'{self.galleon}.{self.sickle}.{self.knut}'


if __name__ == '__main__':
    a_str, b_str = input().split()
    a = Money(*[int(i) for i in a_str.split('.')])
    b = Money(*[int(i) for i in b_str.split('.')])
    print(a + b)
