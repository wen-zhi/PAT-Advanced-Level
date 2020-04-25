#include <iostream>
#include <vector>
#include <string>
#include <set>


class Stack {
public:
    void push(int value);
    int pop();
    int peek_median() {return *(--min_set.end());};
    bool empty() {return data.empty();};
private:
    std::vector<int> data;
    std::multiset<int> min_set, max_set;
    void balance();
};


void Stack::push(int value) {
    data.push_back(value);
    if (min_set.empty()) {
        min_set.insert(value);
    } else {
        if (value <= *(--min_set.end())) {
            min_set.insert(value);
        } else {
            max_set.insert(value);
        }
    }
    balance();
}


int Stack::pop() {
    int value = data.back();
    data.pop_back();
    if (value <= *(--min_set.end())) {
        auto v_iter = min_set.find(value);
        min_set.erase(v_iter);
    } else {
        auto v_iter = max_set.find(value);
        max_set.erase(v_iter);
    }
    balance();
    return value;
}


void Stack::balance() {
    if (min_set.size() > max_set.size() + 1) {
        int value = *(--min_set.end());
        auto v_iter = min_set.find(value);
        min_set.erase(v_iter);
        max_set.insert(value);
    } else if (max_set.size() > min_set.size()) {
        int value = *(max_set.begin());
        auto v_iter = max_set.find(value);
        max_set.erase(v_iter);
        min_set.insert(value);
    }
}


int main() {

    std::ios::sync_with_stdio(false);

    int N;
    std::cin >> N;

    Stack stack;
    while (N--) {
        std::string op;
        std::cin >> op;
        if (op == "Pop") {
            if (!stack.empty()) {
                std::cout << stack.pop() << '\n';
            } else {
                std::cout << "Invalid\n";
            }
        } else if (op == "Push") {
            int value;
            std::cin >> value;
            stack.push(value);
        } else {
            if (!stack.empty()) {
                std::cout << stack.peek_median() << '\n';
            } else {
                std::cout << "Invalid\n";
            }
        }
    }

    return 0;
}
