#include <iostream>
#include <vector>
#include <string>
#include <utility>


int main() {

    int n_user;
    std::cin >> n_user;

    std::vector<std::pair<std::string, std::string>> modified;
    for (int i=0; i<n_user; ++i) {
        std::string name, password;
        bool is_modified = false;
        std::cin >> name >> password;
        for (auto &c : password) {
            switch (c) {
                case '1': c = '@'; is_modified = true; break;
                case '0': c = '%'; is_modified = true; break;
                case 'l': c = 'L'; is_modified = true; break;
                case 'O': c = 'o'; is_modified = true; break;
                default: break;
            }
        }
        if (is_modified) {
            modified.push_back(std::make_pair(name, password));
        }
    }

    if (modified.size()) {
        std::cout << modified.size() << '\n';
        for (auto &name_passwd : modified) {
            std::cout << name_passwd.first << ' '
                      << name_passwd.second << '\n';
        }
    } else {
        std::cout << "There ";
        if (n_user == 1) {
            std::cout << "is 1 account";
        } else {
            std::cout << "are " << n_user << " accounts";
        }
        std::cout << " and no account is modified";
    }

    return 0;
}
