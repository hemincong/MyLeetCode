#include <vector>
#include <set>
#include "AlgoUtils.h"

using namespace std;

class SummaryRanges {
public:
    SummaryRanges() : _union_map(10001, -1) {
    }

    void addNum(int val) {
        if (_union_map[val] == -1) {
            _union_map[val] = val;
            bound.insert(val);
            _union(val, val + 1);
            _union(val - 1, val);
        }
    }

    vector<vector<int>> getIntervals() {
        vector<vector<int>> ret;
        for (const auto &s: bound) {
            int end = find(s);
            ret.emplace_back(vector<int>{s, end});
        }
        return ret;
    }

private:
    int find(int x) {
        if (_union_map[x] != x) {
            _union_map[x] = find(_union_map[x]);
        }
        return _union_map[x];
    }

    void _union(int x, int y) {
        if (x >= 0 && x <= 10000 && _union_map[x] != -1 && _union_map[y] != -1) {
            auto fx = _union_map[x];
            auto fy = _union_map[y];
            if (fx != fy) {
                _union_map[fx] = fy;
                bound.erase(y);
            }
        }

    }

    vector<int> _union_map;
    set<int> bound;
};


int main(int argc, char **argv) {
    SummaryRanges summaryRanges;
    summaryRanges.addNum(1);      // arr = [1]
    printMatrix(summaryRanges.getIntervals()); // return [[1, 1]]
    summaryRanges.addNum(3);      // arr = [1, 3]
    printMatrix(summaryRanges.getIntervals()); // return [[1, 1], [3, 3]]
    summaryRanges.addNum(7);      // arr = [1, 3, 7]
    printMatrix(summaryRanges.getIntervals()); // return [[1, 1], [3, 3], [7, 7]]
    summaryRanges.addNum(2);      // arr = [1, 2, 3, 7]
    printMatrix(summaryRanges.getIntervals()); // return [[1, 3], [7, 7]]
    summaryRanges.addNum(6);      // arr = [1, 2, 3, 6, 7]
    printMatrix(summaryRanges.getIntervals()); // return [[1, 3], [6, 7]]

    return EXIT_SUCCESS;
}