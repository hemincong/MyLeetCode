//
// Created by mincong.he on 2020/7/22.
//

#include <string>
#include <map>
#include <set>

using namespace std;

/* time out
class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty()) return ""
        if (t.length() > s.length()) return "";

        map<char, int> t_set;
        for (const auto &t_c : t) {
            t_set[t_c]++;
        }

        map<char, int> s_map;
        auto head = 0;
        auto tail = 0;
        auto min_length = INT32_MAX;
        string min_str;
        while (head < s.size()) {
            s_map[s[head]]++;
            bool all_contain = check_all_contain(t_set, s_map);
            while (tail <= head && all_contain) {
                auto temp_str = s.substr(tail, head - tail + 1);
                if (temp_str.length() < min_length) {
                    min_str = temp_str;
                    min_length = min_str.length();
                }
                s_map[s[tail]]--;
                tail++;
                all_contain = check_all_contain(t_set, s_map);
            }
            head++;
        }
        return min_str;
    }

private:
    static bool check_all_contain(const map<char, int> &t_set, const map<char, int> &s_map) {
        bool all_contain = true;
        for (const auto &k : t_set) {
            const map<char, int>::const_iterator& it = s_map.find(k.first);
            if (it == s_map.end() || it->second < k.second) {
                all_contain = false;
                break;
            }
        }
        return all_contain;
    }
};
*/

class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty()) return "";
        if (t.length() > s.length()) return "";
        static const int array_lan = 128;
        std::set<int> ts;

        int t_set[array_lan] = {0};
        int s_map[array_lan] = {0};
        for (const auto &t_c : t) {
            t_set[t_c]++;
            ts.insert(t_c);
        }

        auto head = 0;
        auto tail = 0;
        auto min_length = INT32_MAX;
        string min_str;
        while (head < s.size()) {
            s_map[s[head]]++;
            bool all_contain = check_all_contain(s_map, t_set, ts);
            while (tail <= head && all_contain) {
                auto temp_str = s.substr(tail, head - tail + 1);
                if (temp_str.length() < min_length) {
                    min_str = temp_str;
                    min_length = min_str.length();
                }
                s_map[s[tail]]--;
                tail++;
                all_contain = check_all_contain(s_map, t_set, ts);
            }
            head++;
        }
        return min_str;
    }

private:
    static bool check_all_contain(const int *s, const int *t, const set<int> &v) {
        bool all_contain = true;
        for (const auto &k : v) {
            if (s[k] < t[k]) return false;
        }
        return all_contain;
    }
};

int main(int argc, char **argv) {
    Solution s;
    auto ret1 = s.minWindow("ADOBECODEBANC", "ABC");
    printf("ret1: %s\n", ret1.c_str()); // BANC
    auto ret2 = s.minWindow("MADOBCCABEC", "ABCC");
    printf("ret2: %s\n", ret2.c_str()); // BCCA
    auto ret3 = s.minWindow("aa", "aa");
    printf("ret3: %s\n", ret3.c_str()); // aa
    auto ret4 = s.minWindow("a", "aa");
    printf("ret4: %s\n", ret4.c_str()); // ""
    auto ret5 = s.minWindow("a", "b");
    printf("ret5: %s\n", ret5.c_str()); // ""
    return EXIT_SUCCESS;
}

