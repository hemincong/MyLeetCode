//
// Created by mincong.he on 2021/7/2.
//

class CQueue {
public:
    CQueue() {

    }

    void appendTail(int value) {
        s_1.push(value);
    }

    int deleteHead() {
        if (!s_2.empty()) {
            auto ret = s_2.top();
            s_2.pop();
            return ret;
        } else {
            while (!s_1.empty()) {
                auto n = s_1.top();
                s_1.pop();
                s_2.push(n);
            }
            if (!s_2.empty()) {
                auto ret = s_2.top();
                s_2.pop();
                return ret;
            } else return -1;
        }
    }

private:
    std::stack<int> s_1;
    std::stack<int> s_2;
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */