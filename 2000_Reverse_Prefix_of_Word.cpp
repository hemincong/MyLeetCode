//
// Created by mincong.he on 2022/2/2.
//

#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string reversePrefix(string word, char ch) {
        auto n = word.size();
        bool reversed = false;
        vector<char> s_vec;
        for (int i = 0; i < n; ++i) {
            s_vec.emplace_back(word[i]);
            if (word[i] == ch && !reversed) {
                std::reverse(s_vec.begin(), s_vec.end());
                reversed = true;
            }
        }
        s_vec.emplace_back('\0');
        return {&s_vec.at(0)};
    }
};