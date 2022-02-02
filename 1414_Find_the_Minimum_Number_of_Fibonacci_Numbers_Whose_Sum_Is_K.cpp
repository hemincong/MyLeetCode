//
// Created by mincong.he on 2022/2/3.
//

#include "AlgoUtils.h"

using namespace std;

class Solution_2 {
public:
    int findMinFibonacciNumbers(int k) {
        vector<int> fib(2);
        fib[0] = 1;
        fib[1] = 1;
        int i = 1;
        auto temp = fib[i] + fib[i - 1];
        while (temp <= k) {
            fib.push_back(temp);
            i++;
            temp = fib[i] + fib[i - 1];
        }

        int count = 0;
        for (int j = fib.size() - 1; j >= 0 && k > 0; j--) {
            if (fib[j] <= k) {
                k -= fib[j];
                count++;
            }
        }

        return count;
    }
};

class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        vector<int> fib{
                1, 2, 3, 5, 8,
                13, 21, 34, 55, 89,
                144, 233, 377, 610, 987,
                1597, 2584, 4181, 6765, 10946,
                17711, 28657, 46368, 75025, 121393,
                196418, 317811, 514229, 832040, 1346269,
                2178309, 3524578, 5702887, 9227465, 14930352,
                24157817, 39088169, 63245986, 102334155, 165580141,
                267914296, 433494437, 701408733
        };

        int count = 0;
        for (int j = fib.size() - 1; j >= 0 && k > 0; j--) {
            if (fib[j] <= k) {
                k -= fib[j];
                count++;
            }
        }

        return count;
    }
};

int main(int argc, char **argv) {
    Solution s;
    EXPECT_EQ(s.findMinFibonacciNumbers(5), 1);
    EXPECT_EQ(s.findMinFibonacciNumbers(7), 2);
    EXPECT_EQ(s.findMinFibonacciNumbers(10), 2);
    EXPECT_EQ(s.findMinFibonacciNumbers(8), 1);
    EXPECT_EQ(s.findMinFibonacciNumbers(19), 3);
    return EXIT_SUCCESS;
}