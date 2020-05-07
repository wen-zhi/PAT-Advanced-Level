#include <iostream>
#include <string>
#include <map>
#include <regex>
#include <utility>
#include <algorithm>


std::string to_lower(std::string s) {
    for (auto &c : s) {
        c = std::tolower(c);
    }
    return s;
}


bool
comp(const std::pair<const std::string, int> &kv1,
     const std::pair<const std::string, int> &kv2)
{
    if (kv1.second < kv2.second) {
        return true;
    } else if (kv1.second > kv2.second) {
        return false;
    }
    return kv1.first > kv2.first;
}


std::pair<const std::string, int>
most_common_word(const std::string &text)
{
    std::regex pattern("[[:alpha:][:digit:]]+");
    std::map<std::string, int> counter;
    for (std::sregex_iterator iter(text.begin(), text.end(), pattern), end_iter;
         iter!=end_iter; ++iter)
    {
        counter[to_lower(iter->str())] += 1;
    }
    auto res = std::max_element(counter.begin(), counter.end(), comp);
    return *res;
}


int main() {

    std::string text;
    
    std::getline(std::cin, text);
    auto res = most_common_word(text);
    std::cout << res.first << ' ' << res.second << '\n';

    return 0;
}
