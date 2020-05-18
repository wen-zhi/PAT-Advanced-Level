#include <iostream>
#include <vector>
#include <string>


std::string
kuchiguse(const std::vector<std::string> &sentences, std::size_t min_len)
{
    std::size_t start_pos = 0;
    for (std::size_t i=1; i<=min_len; ++i) {
        // get the -ith char of the first sentence
        char c = sentences[0][sentences[0].size()-i];
        bool all_euqal = true;
        for (std::size_t j=1; j!=sentences.size(); ++j) {
            if (sentences[j][sentences[j].size()-i] != c) {
                all_euqal = false;
            }
        }
        if (all_euqal) {
            start_pos = i;
        } else {
            break;
        }
    }
    if (start_pos > 0) {
        return sentences[0].substr(sentences[0].size()-start_pos);
    } else {
        return "nai";
    }
}


int main() {

    int n_sentence;
    std::cin >> n_sentence;
    std::cin.ignore();

    std::vector<std::string> sentences;
    std::size_t min_len = 257;
    while (n_sentence--) {
        std::string sentence;
        std::getline(std::cin, sentence);
        sentences.push_back(sentence);
        min_len = sentence.size() < min_len ? sentence.size() : min_len; 
    }
    std::cout << kuchiguse(sentences, min_len) << '\n';

    return 0;
}
