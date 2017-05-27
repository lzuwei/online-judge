//
// Created by Li Zuwei on 10/11/16.
//

#ifndef EPI_7_6_H
#define EPI_7_6_H
#include <string>

/**
 * Reverse words in a sentence.
 * Eg: Alice likes Paul -> Paul likes Alice
 * @param s inpute sentence
 * @return reversed sentence
 */
std::string reverse_words(const std::string& s) {
    // reverse the entire sentence then reverse individual words
    std::string new_s(s); // make a new copy of the string
    std::reverse(new_s.begin(), new_s.end());

    //word level reversal
    std::string::size_type n = 0, prev_n = 0;
    std::string::iterator it = new_s.begin();
    while((n = new_s.find(" ", prev_n)) != std::string::npos) {
        std::reverse(it + prev_n, it + n);
        prev_n = n + 1;
    }
    std::reverse(it + prev_n, new_s.end());
    return new_s;
}
#endif //EPI_7_6_H
