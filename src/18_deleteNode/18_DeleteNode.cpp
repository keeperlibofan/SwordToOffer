//
// Created by seadream on 2018/12/13.
//
class Solution {
public:
    bool match(char* str, char* pattern)
    {
        if (str == nullptr || pattern == nullptr) {
            return false;
        }
        return matchCore(str, pattern);
    }

    bool matchCore(char *str, char *pattern) {
        if (*str == '\0' && *pattern == '\0') {
            return true;
        }
        if (*str != '\0' && *pattern == '\0') {
            return false;
        }
        if (*(pattern+1) == '*') {
            if (*pattern == *str || (*pattern == '.' && *str != 0)) {
                return matchCore(str+1, pattern+2) ||
                       matchCore(str, pattern+2) ||
                       matchCore(str+1, pattern);
            } else { // 当str为0的情况下,或者当 *pattern != *str 的情况下
                return matchCore(str, pattern+2);
            }
        }
        if (*pattern == *str || (*pattern == '.' && *str != '\0')) {
            return matchCore(str+1, pattern+1);
        }

        return false;
    }
};
