#include <iostream>
#include <vector>
#include <string>
#include <numeric>


class Fraction {
public:
    Fraction() = default;
    Fraction(int numerator, int denominator);
    int numerator, denominator;
private:
    int _gcd(int a, int b);
};


Fraction::Fraction(int numerator, int denominator = 1) {
    this->numerator = numerator;
    this->denominator = denominator;
    if (numerator < 0) numerator *= -1;
    int factor = Fraction::_gcd(numerator, denominator);
    this->numerator /= factor;
    this->denominator /= factor;
}


int Fraction::_gcd(int a, int b) {
    while (b > 0) {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}


Fraction operator+(const Fraction &f1, const Fraction &f2) {
    int numerator = f1.numerator * f2.denominator +
                    f2.numerator * f1.denominator;
    int denominator = f1.denominator * f2.denominator;
    return Fraction(numerator, denominator);
}


std::ostream &operator<<(std::ostream &os, const Fraction &f) {
    std::string sign;
    int numerator = f.numerator;
    if (numerator < 0) {
        sign = '-';
        numerator *= -1;
    }
    if (numerator != 0) {
        int integer_part = numerator / f.denominator;
        numerator %= f.denominator;
        if (integer_part != 0) {
            os << sign << integer_part;
            if (numerator != 0) {
                os << ' ' << numerator << '/' << f.denominator;
            }
        } else {
            os << sign << numerator << '/' << f.denominator;
        }
    } else {
        os << '0';
    }
    return os;
}


int main() {

    int n_fraction;
    std::cin >> n_fraction;
    std::vector<Fraction> fractions;
    while (n_fraction--) {
        int numerator, denominator;
        std::scanf("%d/%d", &numerator, &denominator);
        fractions.push_back(Fraction(numerator, denominator));
    }
    std::cout << std::accumulate(fractions.begin(), fractions.end(), Fraction(0));
    std::cout << '\n';

    return 0;
}
