#include <vector>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    double mincostToHireWorkers(vector<int> &quality, vector<int> &wage, int k) {
        typedef pair<double, int> wage_index_pair;
        vector<wage_index_pair> workers;
        for (int i = 0; i < quality.size(); ++i) {
            workers.emplace_back(double(wage[i]) / double(quality[i]), quality[i]);
        }

        auto wage_index_pair_compare = [](wage_index_pair &p1, wage_index_pair &p2) {
            return p1.first < p2.first;
        };
        sort(workers.begin(), workers.end(), wage_index_pair_compare);

        std::priority_queue<int> q;

        int total_quality = 0;
        double ret = std::numeric_limits<double>::max();

        for (auto& [r, w]: workers) {
            if (q.size() < k - 1) {
                q.push(w);
                total_quality += w;
            } else {
                ret = min(ret, double(total_quality + w) * r);
                if (q.empty()) continue;
                int m_w = q.top();
                if (m_w > w) {
                    q.pop();
                    q.push(w);
                    total_quality = total_quality - m_w + w;
                }
            }
        }

        return ret;
    }
};

int main(int argc, char **argv) {
    Solution s;

    vector<int> quality_1{10, 20, 5};
    vector<int> wage_1{70, 50, 30};
    int k_1 = 2;
    double ret_1 = 105.00000;
    EXPECT_ALMOST_EQ(s.mincostToHireWorkers(quality_1, wage_1, k_1), ret_1, 0.00001)

    vector<int> quality_2{3, 1, 10, 10, 1};
    vector<int> wage_2{4, 8, 2, 2, 7};
    int k_2 = 3;
    double ret_2 = 30.66667;
    EXPECT_ALMOST_EQ(s.mincostToHireWorkers(quality_2, wage_2, k_2), ret_2, 0.00001)

    return EXIT_SUCCESS;
}