//
// Created by mincong.he on 2019/10/12.
//

#include <vector>
#include <cstdio>
#include <queue>
#include <algorithm>

bool compare(const std::pair<int, int> &a, const std::pair<int, int> &b) {
    return a.first > b.first;
}

int get_minimum_stop(int L, int P, std::vector<std::pair<int, int> > &stop) {
    std::priority_queue<int> _big_queue;
    int ret = 0;
    stop.push_back(std::make_pair(0, 0));
    std::sort(stop.begin(), stop.end(), compare);
    for (int i = 0; i < stop.size(); ++i) {
        int dis = L - stop[i].first;
        if (dis > P) {
            while (!_big_queue.empty() && dis > P) {
                int f = _big_queue.top();
                P += f;
                _big_queue.pop();
                ret++;
            }
            if (_big_queue.empty() && dis > P) {
                return -1;
            }
        }
        P -= dis;
        L = stop[i].first;
        _big_queue.push(stop[i].second);
    }
    return ret;
}

int main() {
    std::vector<std::pair<int, int> > stop;
    int N;
    int L;
    int P;
    int distance;
    int fuel;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &distance, &fuel);
        stop.push_back(std::make_pair(distance, fuel));
    }
    scanf("%d %d", &L, &P);
    printf("%d\n", get_minimum_stop(L, P, stop));
    return 0;
}