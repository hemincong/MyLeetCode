//
// Created by mincong.he on 2019/10/10.
//
#include <vector>

using namespace std;

bool compare(const std::vector<int> &a, const std::vector<int> &b) {
    return a.at(0) < b.at(0);
}

class Solution {
public:
    int findMinArrowShots(vector<vector<int>> &points) {
        if (points.empty()) {
            return 0;
        }

        std::sort(points.begin(), points.end(), compare);

        int shoot_num = 1;
        int shoot_begin = points.at(0).at(0);
        int shoot_end = points.at(0).at(1);

        for (int i = 1; i < points.size(); i++) {
            auto current_point = points.at(i);
            auto current_point_begin = current_point.at(0);
            auto current_point_end = current_point.at(1);
            if (current_point_begin >= shoot_begin && current_point_begin <= shoot_end) {
                // 已经排过序
                shoot_begin = current_point_begin;
                if (current_point_end < shoot_end) {
                    shoot_end = current_point_end;
                }
            } else {
                shoot_num++;
                shoot_begin = current_point_begin;
                shoot_end = current_point_end;
            }
        }

        return shoot_num;
    }
};

int main(int argc, char **argv) {
    Solution s;
    std::vector<std::vector<int> > points;
    points.emplace_back((std::vector<int>({10, 16})));
    points.emplace_back((std::vector<int>({2, 8})));
    points.emplace_back((std::vector<int>({1, 6})));
    points.emplace_back((std::vector<int>({7, 12})));
    auto ret_1 = s.findMinArrowShots(points);
    printf("ret 1 : %d\n", ret_1);
    assert(ret_1 == 2);

    std::vector<std::vector<int> > points_2;
    points_2.emplace_back((std::vector<int>({1, 2})));
    points_2.emplace_back((std::vector<int>({2, 3})));
    points_2.emplace_back((std::vector<int>({3, 4})));
    points_2.emplace_back((std::vector<int>({4, 5})));
    auto ret_2 = s.findMinArrowShots(points_2);
    printf("ret 2 : %d\n", ret_2);
    assert(ret_2 == 2);
    return EXIT_SUCCESS;
}