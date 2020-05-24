

class Fraction():
    def __init__(self, numerator, denominator=1):
        self.numerator = numerator
        self.denominator = denominator
        factor = self._gcd(abs(numerator), denominator)
        if factor > 0:
            self.numerator //= factor
            self.denominator //= factor

    def __add__(self, other):
        numerator = (self.numerator * other.denominator +
                     other.numerator * self.denominator)
        denominator = self.denominator * other.denominator
        return Fraction(numerator, denominator)

    def _gcd(self, a, b):
        """gcd(a, b) = gcd(a % b, b) = gcd(b, a % b)"""
        while b > 0:
            a, b = b, a % b
        return a

    def __str__(self):
        sign = '' if self.numerator > 0 else '-'
        if self.numerator != 0:
            integer_part, numerator = divmod(abs(self.numerator),
                                             self.denominator)
            fraction_part = f'{numerator}/{self.denominator}'
            if integer_part != 0:
                res = sign + str(integer_part)
                if numerator != 0:
                    res += ' ' + fraction_part
            else:
                res = sign + fraction_part
        else:
            res = '0'
        return res


if __name__ == '__main__':
    _ = input()
    fractions = [Fraction(*[int(i) for i in deno_nume.split('/')])
                 for deno_nume in input().split()]
    print(sum(fractions, Fraction(0)))
