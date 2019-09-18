//
// Created by mincong.he on 2019/9/18.
//

#include <stack>
#include <iostream>

using namespace std;

class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {

    }

    /** Push element x to the back of queue. */
    void push(int x) {
        _push_stack.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if (!_pop_stack.empty()) {
            int r = _pop_stack.top();
            _pop_stack.pop();
            return r;
        }

        adjust();

        auto r = _pop_stack.top();
        _pop_stack.pop();
        return r;
    }

    /** Get the front element. */
    int peek() {
        if (!_pop_stack.empty()) {
            int r = _pop_stack.top();
            return r;
        }

        adjust();

        return _pop_stack.top();
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return (_push_stack.empty() && _pop_stack.empty());
    }

private:
    void adjust() {
        while (!_push_stack.empty()) {
            int r = _push_stack.top();
            _push_stack.pop();
            _pop_stack.push(r);
        }
    }

    stack<int> _push_stack;
    stack<int> _pop_stack;
};

int main(int argc, char **argv) {
    MyQueue Q;
    std::cout << "empty: " << Q.empty() << std::endl;
    Q.push(1);
    std::cout << "empty: " << Q.empty() << std::endl;
    Q.push(2);
    Q.push(3);
    Q.push(4);
    std::cout << "peek: " << Q.peek() << std::endl;
    Q.pop();
    std::cout << "peek: " << Q.peek() << std::endl;
    return EXIT_SUCCESS;
}