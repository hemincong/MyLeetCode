//
// Created by mincong.he on 2025/4/17.
//
class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        std::map<int, std::vector<int>> count_map;
        for (int i = 0; i < nums.size(); ++i) {
            count_map[nums[i]].push_back(i);
        }

        int total = 0;
        for (auto &[_, s]: count_map) {
            for (int i = 0; i < s.size(); ++i) {
                for (int j = i + 1; j < s.size(); ++j) {
                    //if (j == i) continue;
                    if ((s[i] * s[j]) % k == 0) {
                        total++;
                    }
                }
            }
        }
        return total;
    }
};
    
class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        int count = 0;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                if (nums[i] != nums[j]) continue;

                if (i * j % k == 0) count++;
            }
        }
        return count;
    }
};