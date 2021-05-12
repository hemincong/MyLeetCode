//
// Created by mincong.he on 2021/5/12.
//

#include <vector>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    vector<int> xorQueries(vector<int> &arr, vector<vector<int>> &queries) {
        auto n = arr.size();
        vector<int> xors(n + 1);
        vector<int> ret;
        for (int i = 0; i < n; ++i) {
            xors[i + 1] = xors[i] ^ arr[i];
        }
        for (const auto & q : queries) {
            auto temp = xors[q[0]] ^ xors[q[1] + 1];
            ret.push_back(temp);
        }
        return ret;
    }
};

int main(int argc, char **argv) {
    Solution s;
    vector<int> arr_1{1, 3, 4, 8};
    vector<vector<int>> queries_1{{0, 1},
                                  {1, 2},
                                  {0, 3},
                                  {3, 3}};
    vector<int> ret_1{2, 7, 14, 8};
    assertArray(s.xorQueries(arr_1, queries_1), ret_1);

    vector<int> arr_2{4, 8, 2, 10};
    vector<vector<int>> queries_2{{2, 3},
                                  {1, 3},
                                  {0, 0},
                                  {0, 3}};
    vector<int> ret_2{8, 0, 4, 4};
    assertArray(s.xorQueries(arr_2, queries_2), ret_2);
    return EXIT_SUCCESS;
}