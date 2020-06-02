//
// Created by mincong.he on 2020/6/2.
//

#include <string>
#include <map>

using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        if (str.empty() && !pattern.empty()) return false;

        char tmp[64];
        memset(tmp, '\0', 64);
        int temp_index = 0;
        int pattern_index = 0;
        int str_index = 0;
        map<char, string> dict;
        map<string, char> r_dict;
        char key;
        string value;
        do {
            auto c = str[str_index];
            str_index++;
            if (c == ' ' || str_index == str.size() + 1) {
                key = pattern[pattern_index];
                value = string(tmp);
                //printf("key: %c, value: %s\n", key, value.c_str());
                memset(tmp, '\0', 64);
                temp_index = 0;

                if (dict.find(key) == dict.end() && r_dict.find(value) == r_dict.end()) {
                    dict[key] = value;
                    r_dict[value] = key;
                } else if (dict[key] != value && r_dict[value] != key) {
                    return false;
                }
                pattern_index++;
                if (pattern_index > pattern.size()) {
                    return false;
                }
            } else {
                tmp[temp_index] = c;
                temp_index++;
            }
        } while (str_index <= str.size());
        return pattern_index >= pattern.size();
    }
};

int main(int argc, char **argv) {
    Solution solution;
    assert(!solution.wordPattern("he", "unit"));
    assert(!solution.wordPattern("abba", "dog dog dog dog"));
    assert(solution.wordPattern("abba", "dog cat cat dog"));
    assert(!solution.wordPattern("abba", "dog cat cat fish"));
    assert(!solution.wordPattern("aaaa", "dog cat cat dog"));
    assert(!solution.wordPattern("", "dog dog dog dog"));
    assert(!solution.wordPattern("aaaa", ""));
    assert(!solution.wordPattern("aaaa", "dog dog"));
    assert(!solution.wordPattern("aa", "dog dog dog dog"));
    assert(!solution.wordPattern("aa", "dog dog dog fish"));
    assert(!solution.wordPattern("aa", "fish dog dog fish"));

    return EXIT_SUCCESS;
}