#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>


class User {
public:
    // constructor
    User() = default;
    User(int u_id, int n_problem):
        u_id(u_id) {scores = std::vector<int>(n_problem, -1);};
    // member
    int u_id;
    int total_score = 0;
    int n_solved = 0;
    bool submit_succeed = false;
    std::vector<int> scores;
    static std::vector<int> full_marks;
    // member func
    void update_score(int p_id, int new_score);
};


void User::update_score(int p_id, int new_score) {
    if (new_score == -1) {
        new_score = 0;
    } else {
        submit_succeed = true;
    }
    int old_score = scores[p_id-1];
    if (old_score != -1) {
        if (new_score > old_score) {
            scores[p_id-1] = new_score;
            total_score += (new_score - old_score);
            if (new_score == full_marks[p_id-1]) ++n_solved;
        }
    } else {
        scores[p_id-1] = new_score;
        total_score += new_score;
        if (new_score == full_marks[p_id-1]) ++n_solved;
    }
}


bool operator<(const User &u1, const User &u2) {
    if (u1.total_score > u2.total_score) {
        return true;
    } else if (u1.total_score < u2.total_score) {
        return false;
    }
    if (u1.n_solved > u2.n_solved) {
        return true;
    } else if (u1.n_solved < u2.n_solved) {
        return false;
    }
    return u1.u_id < u2.u_id;
}


std::ostream &operator<<(std::ostream &os, const User &user) {
    os << std::setfill('0')
       << std::setw(5) << user.u_id
       << std::setfill(' ');
    os << ' ' << user.total_score;
    for (auto &score : user.scores) {
        std::cout << ' ';
        if (score != -1) {
            std::cout << score;
        } else {
            std::cout << '-';
        }
    }
    return os;
}


std::vector<int> User::full_marks;


int main() {

    std::ios::sync_with_stdio(false);

    int n_user, n_problem, n_submit;
    std::cin >> n_user >> n_problem >> n_submit;
    for (int i=0; i<n_problem; ++i) {
        int i_full_marks;
        std::cin >> i_full_marks;
        User::full_marks.push_back(i_full_marks);
    }
    std::vector<User> users;
    for (int i=1; i<=n_user; ++i) {
        users.push_back(User(i, n_problem));
    }
    while (n_submit--) {
        int u_id, p_id, score;
        std::cin >> u_id >> p_id >> score;
        users[u_id-1].update_score(p_id, score);
    }
    std::sort(users.begin(), users.end());
    int last_rank = 1, last_score = users.front().total_score;
    for (int i=1; i<=n_user; ++i) {
        int rank;
        if (users[i-1].total_score == last_score) {
            rank = last_rank;
        } else {
            rank = i;
            last_rank = rank;
            last_score = users[i-1].total_score;
        }
        if (users[i-1].submit_succeed) {
            std::cout << rank << ' ' << users[i-1] << '\n';
        }
    }

    return 0;
}
