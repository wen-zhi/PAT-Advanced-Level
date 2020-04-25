#include <iostream>
#include <vector>
#include <algorithm>


std::vector<int>
mice_and_rice(std::vector<int> order, std::vector<int> &mouse, int group_size)
{
    int n_player = order.size();
    std::vector<int> rounds(n_player);
    int round = 1;
    while (order.size() > 1) {
        std::vector<int> winners;
        for (std::size_t i=0; i!=order.size();) {
            std::vector<int> group;
            int winner, fattest_mice = -1;
            for (int count=0; count<group_size && i!=order.size(); ++count) {
                int player = order[i];
                if (mouse[player] > fattest_mice) {
                    winner = player;
                    fattest_mice = mouse[player];
                }
                group.push_back(order[i++]);
            }
            winners.push_back(winner);
            for (auto &player : group) {
                if (player != winner) {
                    rounds[player] = round;
                }
            }
        }
        ++round;
        order = winners;
    }
    rounds[order.front()] = round;

    std::vector<int> players;
    for (int i=0; i<n_player; ++i) {
        players.push_back(i);
    }
    std::sort(players.begin(), players.end(),
              [rounds](const int &p1, const int &p2) {return rounds[p1] > rounds[p2];});
    std::vector<int> ranks(n_player);
    int last_player = players.front();
    ranks[last_player] = 1;
    int rank = 1;
    for (std::size_t i=0; i!=players.size(); ++i) {
        if (rounds[players[i]] == rounds[last_player]) {
            ranks[players[i]] = ranks[last_player];
        } else {
            ranks[players[i]] = rank;
        }
        ++rank;
        last_player = players[i];
    }
    return ranks;
}


int main() {

    int n_player, group_size;
    std::cin >> n_player >> group_size;

    std::vector<int> mouse;
    for (int i=0; i<n_player; ++i) {
        int mice;
        std::cin >> mice;
        mouse.push_back(mice);
    }
    std::vector<int> order;
    for (int i=0; i<n_player; ++i) {
        int player;
        std::cin >> player;
        order.push_back(player);
    }
    
    std::vector<int> ranks = mice_and_rice(order, mouse, group_size);
    for (auto iter=ranks.begin(); iter!=ranks.end()-1; ++iter) {
        std::cout << *iter << ' ';
    }
    std::cout << ranks.back() << '\n';

    return 0;
}
