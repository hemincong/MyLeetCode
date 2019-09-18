//
// Created by mincong.he on 2019/9/18.
//

#include <cstdio>
#include <deque>

using namespace std;

class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {

    }

    /** Push element x onto stack. */
    void push(int x) {
        q.push_front(x);
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        auto front = q.front();
        q.pop_front();
        return front;
    }

    /** Get the top element. */
    int top() {
        return q.front();
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return q.empty();
    }

private:
    deque<int> q;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

int main(){
    MyStack S;
    S.push(1);
    S.push(2);
    S.push(3);
    S.push(4);
    printf("%d\n", S.top());
    S.pop();
    printf("%d\n", S.top());
    S.push(5);
    printf("%d\n", S.top());
    return 0;
}