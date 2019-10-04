//
// Created by mincong.he on 2019/10/2.
//

#include <queue>


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
                _small_queue.push(tmp);
                _big_queue.pop();
                _big_queue.push(num);
            } else {
                _small_queue.push(num);
            }
        } else if (_big_queue.size() < _small_queue.size()) {
            if (num > _small_queue.top()) {
                auto tmp = _small_queue.top();
                _big_queue.push(tmp);
                _small_queue.pop();
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
    MedianFinder M;
    int test[] = {1, 2, 3, 4, 6, 7, 8, 9, 10};
    //int test[] = {12, 10, 13, 11, 5, 15, 1, 11, 6, 17, 14, 8, 17, 6, 4, 16, 8, 10, 2, 12, 0};
    for (int i : test) {
        M.addNum(i);
        printf("========%lf\n", M.findMedian());
    }
    return 0;
}