//
// Created by mincong.he on 2022/3/30.
//

#include "AlgoUtils.h"
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    vector<int> busiestServers(int k, vector<int> &arrival, vector<int> &load) {
        set<int> available;
        for (int i = 0; i < k; i++) {
            available.insert(i);
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> busy;
        vector<int> requests(k);
        for (int i = 0; i < arrival.size(); i++) {
            while (!busy.empty() && busy.top().first <= arrival[i]) {
                available.insert(busy.top().second);
                busy.pop();
            }
            if (available.empty()) {
                continue;
            }
            auto p = available.lower_bound(i % k);
            if (p == available.end()) {
                p = available.begin();
            }
            requests[*p]++;
            busy.emplace(arrival[i] + load[i], *p);
            available.erase(p);
        }
        int maxRequest = *max_element(requests.begin(), requests.end());
        vector<int> ret;
        for (int i = 0; i < k; i++) {
            if (requests[i] == maxRequest) {
                ret.push_back(i);
            }
        }
        return ret;
    }
};

int main(int argc, char **argv) {
    Solution s;
    vector<int> arrival_1{1, 2, 3, 4, 5};
    vector<int> load_1{5, 2, 3, 3, 3};
    vector<int> ret_1{1};
    assertArray(s.busiestServers(3, arrival_1, load_1), ret_1);

    vector<int> arrival_2{1, 2, 3, 4};
    vector<int> load_2{1, 2, 1, 2};
    vector<int> ret_2{0};
    assertArray(s.busiestServers(3, arrival_2, load_2), ret_2);

    vector<int> arrival_3{1, 2, 3};
    vector<int> load_3{10, 12, 11};
    vector<int> ret_3{0, 1, 2};
    assertArray(s.busiestServers(3, arrival_3, load_3), ret_2);
    return EXIT_SUCCESS;
}