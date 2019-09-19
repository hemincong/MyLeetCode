//
// Created by mincong.he on 2019/9/19.
//

#include <cstdio>
#include <queue>
#include <stack>

bool check_is_valid_order(std::queue<int> &order) {
    int n = order.size();

    std::stack<int> s;
    for (int i = 1; i <= n; ++i) {
        s.push(i);

        while (!s.empty() && s.top() == order.front()) {
            s.pop();
            order.pop();
        }
    }

    return s.empty();
}

int main() {
    int n;
    int train;
    scanf("%d", &n);
    while (n) {
        scanf("%d", &train);
        while (train) {
            std::queue<int> order;
            order.push(train);
            for (int i = 1; i < n; i++) {
                scanf("%d", &train);
                order.push(train);
            }
            if (check_is_valid_order(order)) {
                printf("Yes\n");
            } else {
                printf("No\n");
            }
            scanf("%d", &train);
        }
        printf("\n");
        scanf("%d", &n);
    }
    return 0;
}