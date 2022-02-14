//
// Created by mincong.he on 2022/2/14.
//

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> char_count(5, 0);
        for (auto c: text) {
            switch (c) {
                case 'b':
                    char_count[0]++;
                    break;
                case 'a':
                    char_count[1]++;
                    break;
                case 'l':
                    char_count[2]++;
                    break;
                case 'o':
                    char_count[3]++;
                    break;
                case 'n':
                    char_count[4]++;
                    break;
                default:
                    continue;
            }
        }
        char_count[2] = char_count[2] / 2;
        char_count[3] = char_count[3] / 2;
        return *min_element(char_count.begin(), char_count.end());
    }
};