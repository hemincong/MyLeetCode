//
// Created by mincong.he on 2021/1/24.
//

#include <string>
#include <utility>
#include <vector>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        auto n_list_1 = slice_string(std::move(version1), ".");
        auto n_list_2 = slice_string(std::move(version2), ".");

        auto n_1_size = n_list_1.size();
        auto n_2_size = n_list_2.size();
        auto s = n_1_size;
        if (n_1_size > n_2_size) {
            for (int i = 0; i < n_1_size - n_2_size; ++i) n_list_2.push_back(0);
            s = n_1_size;
        }
        if (n_1_size < n_2_size) {
            for (int i = 0; i < n_2_size - n_1_size; ++i) n_list_1.push_back(0);
            s = n_2_size;
        }

        for (int i = 0; i < s; ++i) {
            if (n_list_1[i] > n_list_2[i])
                return 1;
            else if (n_list_1[i] < n_list_2[i])
                return -1;
        }

        return 0;
    }

private:
    vector<int> slice_string(string s, const string &delimiter) {
        size_t pos;
        vector<int> r;
        std::string token;
        while ((pos = s.find(delimiter)) != std::string::npos) {
            token = s.substr(0, pos);
            r.push_back(stoi(token));
            s.erase(0, pos + delimiter.length());
        }
        r.push_back(stoi(s));
        return r;
    }
};

int main(int argc, char **argv) {
    Solution s;
    vector<vector<string>> test_case{
            {"1.01",    "1.001"},
            {"1.0",     "1.0.0"},
            {"0.1",     "1.1"},
            {"1.0.1",   "1"},
            {"7.5.2.4", "7.5.3"}
    };

    vector<int> ret{0, 0, -1, 1, -1};

    for (int i = 0; i < test_case.size(); ++i) {
        std::cout << i << std::endl;
        EXPECT_EQ(s.compareVersion(test_case[i][0], test_case[i][1]), ret[i]);
    }

    return EXIT_SUCCESS;
}