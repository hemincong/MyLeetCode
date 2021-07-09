#include <map>
#include <sstream>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    string countOfAtoms(string formula) {
        stringstream ss;
        map<string, int> sub_count_map;
        get_sub_string_count(formula, 0, sub_count_map);
        for (auto &p: sub_count_map) {
            ss << p.first;
            if (p.second > 1) {
                ss << to_string(p.second);
            }
        }
        return ss.str();
    }

private:
    int get_sub_string_count(const string &formula, int index, map<string, int> &count_map) {
        auto formula_size = formula.size();
        if (index >= formula_size || formula[index] == ')') {
            return index + 1;
        }
        while (index < formula_size) {
            // 左括号，递归下一个单元
            if (formula[index] == '(') {
                map<string, int> sub_count_map;
                index = get_sub_string_count(formula, index + 1, sub_count_map);
                int cnt = 0;
                while (index < formula_size && formula[index] >= '0' && formula[index] <= '9') {
                    cnt = cnt * 10 + formula[index++] - '0';
                }
                if (cnt > 0) {
                    for (auto &n : sub_count_map) {
                        n.second *= cnt;
                    }
                }
                // 合并
                for (auto &n : sub_count_map) {
                    count_map[n.first] += n.second;
                }
            } else if (formula[index] == ')') {
                return index + 1;
            } else {
                vector<char> element_name{formula[index++]};
                while (index < formula_size && formula[index] >= 'a' && formula[index] <= 'z') {
                    element_name.push_back(formula[index++]);
                }
                element_name.push_back('\0');
                int cnt = 0;
                while (index < formula_size && formula[index] >= '0' && formula[index] <= '9') {
                    cnt = cnt * 10 + formula[index++] - '0';
                }
                if (cnt > 0) {
                    count_map[string(&element_name.at(0))] += cnt;
                } else {
                    // 没有数字还有一次
                    // 因为会有重复字母位于不同位置，要加，不能等
                    count_map[string(&element_name.at(0))] += 1;
                }
            }
        }
        return index;
    }
};

int main(int argc, char **argv) {
    Solution s;
    EXPECT_EQ(s.countOfAtoms("H2O"), "H2O");
    EXPECT_EQ(s.countOfAtoms("Mg(OH)2"), "H2MgO2");
    EXPECT_EQ(s.countOfAtoms("K4(ON(SO3)2)2"), "K4N2O14S4");
    EXPECT_EQ(s.countOfAtoms("((HHe28Be26He)9)34"), "Be7956H306He8874");
    return EXIT_SUCCESS;
}