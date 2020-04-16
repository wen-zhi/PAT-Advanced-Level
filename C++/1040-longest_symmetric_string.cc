#include <iostream>
#include <vector>
#include <queue>


struct SubStr {
    std::size_t start, end;
};


SubStr longest_symmetric_string(std::string &s) {
    std::queue<SubStr> Queue;
    // odd substr
    for (std::size_t i=0; i<s.size(); ++i) {
        Queue.push({i, i});
    }
    // even substr
    for (std::size_t i=0; i<s.size()-1; ++i) {
        if (s[i] == s[i+1]) {
            Queue.push({i, i+1});
        }
    }
    SubStr substr;
    while (!Queue.empty()) {
        substr = Queue.front();
        Queue.pop();
        if (substr.start > 0 && substr.end < s.size() - 1 &&
            s[substr.start-1] == s[substr.end+1])
        {
            Queue.push({substr.start-1, substr.end+1});
        }
    }
    return substr;
}


int main() {

    std::string s;
    std::getline(std::cin, s);

    SubStr res = longest_symmetric_string(s);
    std::cout << res.end - res.start + 1 << '\n';

    return 0;
}
