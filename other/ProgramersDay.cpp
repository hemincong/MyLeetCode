//
// Created by mincong.he on 2019/10/31.
//

#include <vector>
#include <iostream>

using namespace std;

// 从100到200共101个数字中按照顺序取10个数，每个数可以重复取，使十个数的总和为1024，求总共有多少种选择，给出最终的选择数量
// 例如，选择的是个数按照顺序分别为100、100、100、100、100、100、104、106、106、108，这十个数的总和为1024，即为其中一种选择

class Solution {
public:
    vector<vector<int>> sum_25() {
        auto r = std::vector<std::vector<int>>();
        auto item = std::vector<int>();
        generate(0, item, 0, r);
        return r;
    }

private:
    void generate(int i, std::vector<int> &item, int sum, std::vector<std::vector<int>> &result) {
        if (i < 0 || i >= 25 || sum > 25 || item.size() > 10) return;

        item.push_back(i);
        sum += i;
        if (sum == 24 && item.size() == 10) {
            result.push_back(item);
        }

        generate(i, item, sum, result);
        item.pop_back();
        sum -= i;
        generate(i + 1, item, sum, result);
    }
};

int main(int argc, char **argv) {
    Solution solution{};
    auto ret = solution.sum_25();
    for (const auto &i : ret) {
        std::cout << "[";
        for (const auto &j : i) {
            std::cout << j << " ";
        }
        std::cout << "]" << std::endl;
    }
    std::cout << "total: " << ret.size() << std::endl;
    return EXIT_SUCCESS;
}