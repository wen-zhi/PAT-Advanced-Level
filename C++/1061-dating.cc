#include <iostream>
#include <string>
#include <array>
#include <cctype>
#include <iomanip>


const std::array<std::string, 7> kWeekName = {
    "MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"
};


int main() {

    std::string day;
    int hour, minute;

    std::string str1, str2;
    std::getline(std::cin, str1);
    std::getline(std::cin, str2);
    bool day_is_found = false;
    for (auto iter1 = str1.begin(), iter2 = str2.begin();
         iter1 != str1.end() && iter2 != str2.end();
         ++iter1, ++iter2)
    {
        if (*iter1 == *iter2) {
            if (!day_is_found) {
                if (*iter1 <= 'G' && *iter1 >= 'A') {
                    day = kWeekName[*iter1 - 'A'];
                    day_is_found = true;
                }
            } else {
                if (*iter1 <= 'N' && *iter1 >= 'A') {
                    hour = *iter1 - 'A' + 10;
                    break;
                } else if (std::isdigit(*iter1)) {
                    hour = *iter1 - '0';
                    break;
                }
            }
        }
    }
    std::string str3, str4;
    std::getline(std::cin, str3);
    std::getline(std::cin, str4);
    for (auto iter1 = str3.begin(), iter2 = str4.begin();
         iter1 != str3.end() && iter2 != str4.end();
         ++iter1, ++iter2)
    {
        if (*iter1 == *iter2 && std::isalpha(*iter1)) {
            minute = std::distance(str3.begin(), iter1);
        }
    }

    std::cout << day << ' ';
    std::cout << std::setfill('0');
    std::cout << std::setw(2) << hour << ':';
    std::cout << std::setw(2) << minute << '\n';
    std::cout << std::setfill(' ');

    return 0;
}
