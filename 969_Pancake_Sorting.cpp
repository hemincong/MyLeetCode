//
// Created by mincong.he on 2022/2/19.
//

#include <vector>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    vector<int> pancakeSort(vector<int> &arr) {
        int n = arr.size();
        vector<int> ret;
        for (int i = n; i > 1; i--) {
            int max_index = max_element(arr.begin(), arr.begin() + i) - arr.begin();
            if (max_index == i - 1) continue;
            std::reverse(arr.begin(), arr.begin() + max_index + 1);
            ret.push_back(max_index + 1);
            std::reverse(arr.begin(), arr.begin() + i);
            ret.push_back(i);
        }
        return ret;

    }
};

int main(int argc, char **argv) {
    Solution s;
    vector<int> test_case_1{3, 2, 4, 1};
    printArray(s.pancakeSort(test_case_1));
    vector<int> test_case_2{1, 2, 3};
    printArray(s.pancakeSort(test_case_2));
    return EXIT_SUCCESS;
}