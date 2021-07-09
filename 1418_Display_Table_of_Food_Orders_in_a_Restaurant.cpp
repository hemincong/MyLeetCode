#include <vector>
#include <unordered_map>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>> &orders) {
        map<string, int> maps;
        vector<vector<string>> as(1, vector<string>(1));
        vector<int> k;
        as[0][0] = "Table";
        for (auto it:orders) {
            maps[it[2] + it[1]] += 1;           //按照菜名+桌数 统计该菜在该桌点了多少次
            if (find(k.begin(), k.end(), stoi(it[1])) == k.end())
                k.push_back(stoi(it[1]));   //统计桌牌
            if (find(as[0].begin(), as[0].end(), it[2]) != as[0].end())
                continue;
            else
                as[0].push_back(it[2]);     //as第一行加入菜名
        }
        sort(as[0].begin() + 1, as[0].end()); //排序第一行菜名
        sort(k.begin(), k.end());  //排序桌牌
        vector<string> m;
        int i = 1;
        for (auto ip:k) {   //桌牌外循环，按行遍历菜名
            for (auto is:as[0]) { //遍历菜名
                if (is == "Table") {     //处理Table
                    m.push_back(to_string(ip));   //m是vector容器，放入桌牌数
                    as.push_back(m);         //m加入as
                    m.clear();
                }         //清除m，下一个桌牌数使用
                else
                    as[i].push_back(to_string(maps[is + to_string(ip)])); //加入对应的点菜数
            }
            i++;  //菜名循环一次，数组i自加一，开始处理下一行
        }
        return as;
    }
};

int main(int argc, char **argv) {
    Solution s;
    return EXIT_SUCCESS;
}