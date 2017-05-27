//
// Created by Li Zuwei on 10/11/16.
//
#include <string>
// 12345
std::string int_to_string(int x) {
    bool is_neg = false;
    std::string x_str;
    if (x < 0) {
        x = -x;
        is_neg = true;
    }

    do {
        x_str += '0' + x % 10;
        x /= 10;
    } while(x);
    if (is_neg)
        x_str.push_back('-');
    std::reverse(x_str.begin(), x_str.end());
    return x_str;
}

//12345
int string_to_int(const std::string& s) {
    int x = 0;
    bool is_neg = false;
    if(s[0] == '-')
        is_neg = true;
    for (int i = is_neg ? 1 : 0; i < s.size(); ++i) {
        int digit = s[i] - '0';
        x = x * 10 + digit;
    }
    return is_neg ? -x : x;
}



