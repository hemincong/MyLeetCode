//
// Created by mincong.he on 2019/10/27.
//

class Solution {
public:
    int game(vector<int>& guess, vector<int>& answer) {
        int sum = 0;
        for (int i = 0; i < guess.size(); i++) {
            if (guess[i] == answer[i]) {
                sum++;
            }
        }
        return sum;
    }
};