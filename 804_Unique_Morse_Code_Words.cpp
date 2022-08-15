//
// Created by mincong.he on 2022/4/10.
//

class Solution {
public:
    int uniqueMorseRepresentations(vector <string> &words) {

        unordered_set <string> t;
        for (const auto &w: words) {
            stringstream ss;
            for (const auto &c: w) {
                ss << m[c - 'a'];
            }
            t.insert(ss.str());
        }
        return t.size();
    }

private:
    const vector <string> m{".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--",
                            "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--",
                            "--.."};
};