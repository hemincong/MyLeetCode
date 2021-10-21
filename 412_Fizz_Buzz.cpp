//
// Created by mincong.he on 2021/10/21.
//

class Solution {
public:
    vector <string> fizzBuzz(int n) {
        vector <string> ret;
        for (int i = 1; i <= n; ++i) {
            if (i % 3 == 0 && i % 5 == 0) {
                ret.emplace_back("FizzBuzz");
            } else if (i % 5 == 0) {
                ret.emplace_back("Buzz");
            } else if (i % 3 == 0) {
                ret.emplace_back("Fizz");
            } else {
                ret.emplace_back(std::to_string(i));
            }
        }
        return ret;
    }
};