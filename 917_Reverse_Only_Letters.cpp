//
// Created by mincong.he on 2022/2/23.
//

#include "AlgoUtils.h"
#include <string>

using namespace std;


#define is_alpha(c) \
    (((c) >= 'a' && (c) <= 'z') || ((c) >= 'A' && (c) <= 'Z'))


class Solution {
public:
    string reverseOnlyLetters(string s) {
        auto n = s.size();
        vector<char> s_vec(&s.at(0), &s.at(0) + n);
        int i = 0;
        int j = n - 1;
        while (i < j) {
            while (i < n && !is_alpha(s_vec[i])) {
                i++;
            }
            while (j >= 0 && !is_alpha(s_vec[j])) {
                j--;
            }
            if (i < j && is_alpha(s_vec[i]) && is_alpha(s_vec[j])) {
                auto temp = s_vec[i];
                s_vec[i] = s_vec[j];
                s_vec[j] = temp;
                i++;
                j--;
            }
        }
        s_vec.push_back('\0');
        return {&s_vec.at(0)};
    }
};

int main(int argc, char **argv) {
    Solution s;
    EXPECT_EQ(s.reverseOnlyLetters("ab-cd"), "dc-ba")
    EXPECT_EQ(s.reverseOnlyLetters("a-bC-dEf-ghIj"), "j-Ih-gfE-dCba")
    EXPECT_EQ(s.reverseOnlyLetters("Test1ng-Leet=code-Q!"), "Qedo1ct-eeLg=ntse-T!")
    return EXIT_SUCCESS;
}