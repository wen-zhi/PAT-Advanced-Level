#include <iostream>
#include <vector>
#include <string>
#include <stack>


std::string
check_pop_sequence(std::vector<int> &seq, std::size_t stack_size)
{
    std::stack<int> stack;
    int elem = 1;
    bool is_popseq = true;
    for (int &num : seq) {
        while (elem <= num) {
            if (stack.size() < stack_size) {
                stack.push(elem++);
            } else {
                is_popseq = false;
                break;
            }
        }
        if (stack.top() == num) {
            stack.pop();
        } else {
            is_popseq = false;
            break;
        }
    }
    if (is_popseq) {
        return "YES";
    } else {
        return "NO";
    }
}


int main() {

    std::size_t stack_size;
    int n_elem, n_seq;
    std::cin >> stack_size >> n_elem >> n_seq;

    while (n_seq--) {
        std::vector<int> seq;
        int num;
        for (int i=0; i<n_elem; ++i) {
            std::cin >> num;
            seq.push_back(num);
        }
        std::cout << check_pop_sequence(seq, stack_size) << '\n';
    }

    return 0;
}
