//
// Created by mincong.he on 2019/10/4.
//

#include <vector>

using namespace std;

class Solution {
public:
    int findContentChildren(vector<int> &g, vector<int> &s) {
        std::sort(g.begin(), g.end());
        std::sort(s.begin(), s.end());
        auto s_iter = s.begin();
        auto g_iter = g.begin();
        int count = 0;
        while (g_iter != g.end() && s_iter != s.end()) {
            if (*g_iter <= *s_iter) {
                g_iter++;
                count++;
            }
            s_iter++;
        }

        return count;
    }
};

int main(int argc, char **argv) {
    Solution solve;
    // 3
    std::vector<int> g_1 = {5, 10, 2, 9, 15, 9};
    std::vector<int> s_1 = {6, 1, 20, 3, 8};
    printf("%d\n", solve.findContentChildren(g_1, s_1));

    // 1
    std::vector<int> g_2 = {1, 2, 3};
    std::vector<int> s_2 = {1, 1};
    printf("%d\n", solve.findContentChildren(g_2, s_2));

    // 2
    std::vector<int> g_3 = {1, 1};
    std::vector<int> s_3 = {1, 2, 3};
    printf("%d\n", solve.findContentChildren(g_3, s_3));

    return EXIT_SUCCESS;
}