//
// Created by mincong.he on 2019/10/2.
//

#include <queue>
#include "AlgoUtils.h"

class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {

    }

    void addNum(int num) {
        if (_big_queue.empty()) {
            _big_queue.push(num);
        } else if (_big_queue.size() == _small_queue.size()) {
            if (num < _big_queue.top()) {
                _big_queue.push(num);
            } else {
                _small_queue.push(num);
            }
        } else if (_big_queue.size() > _small_queue.size()) {
            if (num <= _big_queue.top()) {
                auto tmp = _big_queue.top();
                _big_queue.pop();
                _small_queue.push(tmp);
                _big_queue.push(num);
            } else {
                _small_queue.push(num);
            }

        } else if (_big_queue.size() < _small_queue.size()) {
            if (num > _small_queue.top()) {
                auto tmp = _small_queue.top();
                _small_queue.pop();
                _big_queue.push(tmp);
                _small_queue.push(num);
            } else {
                _big_queue.push(num);
            }
        }
    }

    double findMedian() {
        if (_big_queue.size() > _small_queue.size()) {
            return _big_queue.top();
        } else if (_big_queue.size() == _small_queue.size()) {
            return ((double) _big_queue.top() + (double) _small_queue.top()) / 2.0f;
        }
        return _small_queue.top();
    }

private:
    std::priority_queue<double, std::vector<double>, std::less<>> _big_queue;
    std::priority_queue<double, std::vector<double>, std::greater<>> _small_queue;
};

int main(int argc, char **argv) {
    MedianFinder medianFinder;
    medianFinder.addNum(1);
    medianFinder.addNum(2);
    EXPECT_EQ(medianFinder.findMedian(), 1.5);
    medianFinder.addNum(3);
    EXPECT_EQ(medianFinder.findMedian(), 2.0);
    return 0;
}