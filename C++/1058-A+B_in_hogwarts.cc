#include <cstdio>


int main() {

    long long int galleon, sickle, knut;

    std::scanf("%lld.%lld.%lld", &galleon, &sickle, &knut);
    long long int knuts_a = ((galleon * 17) + sickle) * 29 + knut;

    std::scanf("%lld.%lld.%lld", &galleon, &sickle, &knut);
    long long int knuts_b = ((galleon * 17) + sickle) * 29 + knut;

    long long int all_knuts = knuts_a + knuts_b;
    knut = all_knuts % 29;
    sickle = all_knuts / 29 % 17;
    galleon = all_knuts / 29 / 17;

    std::printf("%lld.%lld.%lld\n", galleon, sickle, knut);

    return 0;
}
