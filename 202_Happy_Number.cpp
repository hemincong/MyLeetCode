//
// Created by mincong.he on 2019-09-03.
//

#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    static int squareSum(int n) {
        int total = 0;
        int x = 0;
        while (n > 0) {
            x = n % 10;
            total += (x * x);
            n = n / 10;
        }
        return total;
    }

    // 解决可能的无限循环（局部环）可以用快慢指针或者set
    bool isHappy(int n) {
        int slow = n;
        int fast = squareSum(n);
        while (slow != fast) {
            slow = squareSum(slow);
            fast = squareSum(squareSum(fast));
        }
        return slow == 1;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main(int argc, char **argv) {
    string line(argv[1]);
    int n = stringToInteger(line);

    bool ret = Solution().isHappy(n);

    string out = boolToString(ret);
    cout << out << endl;
    return 0;
}