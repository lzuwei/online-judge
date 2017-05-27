//
// Created by Li Zuwei on 10/11/16.
//

#ifndef EPI_7_5_H
#define EPI_7_5_H
#include <string>

bool is_palindromic_sentence(const std::string& s) {
    //compare using 2 indices 1 from head and the other from tail
    //skip all non-alphanumeric letters
    int start = 0, end = s.size() - 1;
    while(start < end) {
        while(!isalpha(s[start])) //keep moving forward while non-alphanumeric letters are detected
            ++start;
        while(!isalpha(s[end])) //likewise move backwards
            --end;
        if(isalpha(s[start]) && isalpha(s[end])) {
            if(tolower(s[start]) != tolower(s[end])) //compare ignore case
                return false; //mismatch return false
        }
        ++start;
        --end;
    }
    return true;
}
#endif //EPI_7_5_H
