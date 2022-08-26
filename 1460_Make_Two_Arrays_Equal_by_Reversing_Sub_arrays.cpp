#include <vector>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        if (target.size() != arr.size()) return false;

        std::unordered_map<int, int> target_count;
        std::unordered_map<int, int> arr_count;

        for (auto t: target) {
            target_count[t]++;
        }

        for (auto a: arr) {
            arr_count[a]++;
        }

        for (auto iter = target_count.begin(); iter != target_count.end(); ++iter) {
            auto [num, count] = *iter;
            if (arr_count[num] != count) return false;
        }
        return true;
    }
};
