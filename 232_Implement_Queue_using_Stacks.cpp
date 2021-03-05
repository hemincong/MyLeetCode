//
// Created by mincong.he on 2019/9/18.
//

#include <stack>
#include <iostream>
#include "AlgoUtils.h"

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
            auto t = _pop_stack.top();
            _pop_stack.pop();
            return t;
        }

        // pop empty
        _move_to_pop_stack();

        auto t = _pop_stack.top();
        _pop_stack.pop();
        return t;

    }

    /** Get the front element. */
    int peek() {
        if (!_pop_stack.empty()) {
            auto t = _pop_stack.top();
            return t;
        }

        // pop empty
        _move_to_pop_stack();

        auto t = _pop_stack.top();
        return t;
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return _pop_stack.empty() && _push_stack.empty();
    }

private:
    void _move_to_pop_stack() {
        while (!_push_stack.empty()) {
            auto t = _push_stack.top();
            _pop_stack.push(t);
            _push_stack.pop();
        }
    }

    stack<int> _pop_stack;
    stack<int> _push_stack;
};

int main(int argc, char **argv) {
    MyQueue Q;
    EXPECT_TRUE(Q.empty())
    Q.push(1);
    EXPECT_FALSE(Q.empty())
    Q.push(2);
    Q.push(3);
    Q.push(4);
    EXPECT_EQ(Q.peek(), 1)
    Q.pop();
    EXPECT_EQ(Q.peek(), 2)

    MyQueue Q_2;
    EXPECT_TRUE(Q_2.empty());
    Q_2.push(1);
    Q_2.push(2);
    Q_2.push(3);
    Q_2.push(4);
    EXPECT_EQ(Q_2.pop(), 1);
    Q_2.push(5);
    EXPECT_EQ(Q_2.pop(), 2);
    EXPECT_EQ(Q_2.pop(), 3);
    EXPECT_EQ(Q_2.pop(), 4);
    EXPECT_EQ(Q_2.pop(), 5);
    return EXIT_SUCCESS;
}