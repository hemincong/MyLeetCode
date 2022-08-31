//
// Created by mincong.he on 2022/8/31.
//
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        unsigned int pop_index = 0;
        stack<int> s;

        for (auto &n : pushed) {
            s.push(n);
            while (!s.empty() && s.top() == popped[pop_index]) {
                s.pop();
                pop_index++;
            }
        }
        return s.empty();
    }
};