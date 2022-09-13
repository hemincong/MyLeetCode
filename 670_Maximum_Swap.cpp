#include <vector>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    int maximumSwap(int num) {
        auto num_str = std::to_string(num);
        vector<char> num_char(&num_str.at(0), &num_str.at(0) + num_str.length());
        vector<char> sorted_num_char(num_char);

        sort(sorted_num_char.begin(), sorted_num_char.end(), greater<>());

        int p1;
        for (int i = 0; i < num_char.size() - 1; ++i) {
            if (sorted_num_char[i] != num_char[i]) {
                p1 = i;
                break;
            }
        }

        int p2 = num_char.size() - 1;
        for (int i = num_char.size() - 1; i > 0; --i) {
            if (num_char[i] == sorted_num_char[p1]) {
                p2 = i;
                break;
            }
        }

        char temp = num_char[p1];
        num_char[p1] = num_char[p2];
        num_char[p2] = temp;
        num_char.push_back('\0');
        return stoi(num_char.data());
    }
};

int main(int argc, char **argv) {
    Solution s;
    EXPECT_EQ(s.maximumSwap(2736), 7236);
    EXPECT_EQ(s.maximumSwap(9973), 9973);
    EXPECT_EQ(s.maximumSwap(98368), 98863);
    return EXIT_SUCCESS;
}