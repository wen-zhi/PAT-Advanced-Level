#include <iostream>
#include <string>
#include <vector>


std::vector<std::size_t>
shuffling (std::vector<std::size_t> &permutation, int n_time) {
    std::vector<std::size_t> cards(54);
    for (int i=0; i<54; ++i) {
        cards[i] = i;
    }
    std::vector<std::size_t> shuffled_cards(54);
    while (n_time--) {
        for (auto c_iter=cards.begin(), p_iter=permutation.begin();
             c_iter!=cards.end(), p_iter!=permutation.end();
             ++c_iter, ++p_iter)
        {
            shuffled_cards[*p_iter-1] = *c_iter;
        }
        std::swap(cards, shuffled_cards);
    }
    return cards;
}


int main() {

    int n_time;
    std::cin >> n_time;
    std::vector<std::size_t> permutation;
    for (int i=0; i<54; ++i) {
        std::size_t idx;
        std::cin >> idx;
        permutation.push_back(idx);
    }
    std::vector<std::size_t> shuffled_cards = shuffling(
        permutation, n_time);
    
    std::vector<std::string> card_type = {"S", "H", "C", "D", "J"};
    for (auto iter = shuffled_cards.begin();
         iter != shuffled_cards.end()-1;
         ++iter)
    {
        std::cout << card_type[*iter / 13] << *iter % 13 + 1 << ' ';
    }
    std::cout << card_type[shuffled_cards.back() / 13]
              << shuffled_cards.back() % 13 + 1 << '\n';

    return 0;
}
