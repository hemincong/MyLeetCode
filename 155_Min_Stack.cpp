//
// Created by mincong.he on 2019/9/19.
//

#include <stack>

using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {

    }

    void push(int x) {
        _stack.push(x);
        if (_min_stack.empty()) {
            _min_stack.push(x);
        } else {
            auto min_top = _min_stack.top();
            if (x < min_top) {
                _min_stack.push(x);
            } else {
                _min_stack.push(min_top);
            }
        }
    }

    void pop() {
        _stack.pop();
        _min_stack.pop();
    }

    int top() {
        return _stack.top();
    }

    int getMin() {
        return _min_stack.top();
    }

private:
    stack<int> _stack;
    stack<int> _min_stack;
};

int main() {
    MinStack S;
    printf("%d\n", S.getMin());
    S.push(-2);
    S.push(0);
    S.push(-3);
    printf("%d\n", S.getMin());
    S.pop();
    printf("%d\n", S.top());
    printf("%d\n", S.getMin());
    return 0;
}