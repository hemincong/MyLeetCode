//
// Created by mincong.he on 2022/1/27.
//

#include <string>
#include "AlgoUtils.h"

using namespace std;

#define is_word(c) \
    ((c) >= 'a' && (c) <= 'z') || ((c) >= 'A' && (c) <= 'Z')

#define is_number(c) \
    ((c) >= '0' && (c) <= '9')

class Solution {
public:
    int countValidWords(string sentence) {
        int token_count = 0;
        auto n = sentence.size();
        vector<vector<char>> all_word;
        vector<char> temp;
        for (int i = 0; i < n; ++i) {
            auto c = sentence[i];
            if (c == ' ') {
                if (!temp.empty()) all_word.emplace_back(temp);
                temp.clear();
                continue;
            }
            temp.emplace_back(c);
        }
        if (!temp.empty()) all_word.emplace_back(temp);
        for (const auto &w: all_word) {
            if (check(w)) {
                token_count++;
            }
        }
        return token_count;
    }

    bool check(const vector<char> &word) {
        auto n = word.size();
        // 只有一个字符的时候 只不能是-
        if (word.size() == 1 && is_number(word[0]))
            return false;
        if (word.size() == 1 && word[0] != '-')
            return true;
        // 头不能为符号，任何符号
        if (!is_word(word[0])) {
            return false;
        }

        // 中间只有一个-和字母
        bool has_link_symbol = false;
        for (int i = 0; i < n - 1; ++i) {
            if (is_number(word[i])) {
                return false;
            } else if (!is_word(word[i])) {
                if (word[i] == '-') {
                    if (has_link_symbol) {
                        return false;
                    } else {
                        has_link_symbol = true;
                        continue;
                    }
                }
                return false;
            }
        }

        auto tail = word[n - 1];
        // for "q-, " , 注意！这个不知道是什么规则，不是两个符号的问题，因为 "xx-xx,"是可以的！
        if (n > 2) {
            if (!(is_word(tail)) && word[n - 2] == '-') return false;
        }
        if (tail == '-' || is_number(tail)) return false;
        return true;
    }
};

int main(int argc, char **argv) {
    Solution s;
    EXPECT_EQ(s.countValidWords("cat and  -"), 2);
    EXPECT_EQ(s.countValidWords("cat and  !"), 3);
    EXPECT_EQ(s.countValidWords("cat and  dog"), 3);
    EXPECT_EQ(s.countValidWords("!this  1-s b8d!"), 0);
    EXPECT_EQ(s.countValidWords("alice and  bob are playing stone-game10"), 5);
    EXPECT_EQ(s.countValidWords("f    6c x2"), 1);
    EXPECT_EQ(s.countValidWords("q-, "), 0);
    EXPECT_EQ(s.countValidWords(
            " 62   nvtk0wr4f  8 qt3r! w1ph 1l ,e0d 0n 2v 7c.  n06huu2n9 s9   ui4 nsr!d7olr  q-, vqdo!btpmtmui.bb83lf g .!v9-lg 2fyoykex uy5a 8v whvu8 .y sc5 -0n4 zo pfgju 5u 4 3x,3!wl  fv4   s  aig cf j1 a i  8m5o1  !u n!.1tz87d3 .9    n a3  .xb1p9f  b1i a j8s2 cugf l494cx1! hisceovf3 8d93 sg 4r.f1z9w   4- cb r97jo hln3s h2 o .  8dx08as7l!mcmc isa49afk i1 fk,s e !1 ln rt2vhu 4ks4zq c w  o- 6  5!.n8ten0 6mk 2k2y3e335,yj  h p3 5 -0  5g1c  tr49, ,qp9 -v p  7p4v110926wwr h x wklq u zo 16. !8  u63n0c l3 yckifu 1cgz t.i   lh w xa l,jt   hpi ng-gvtk8 9 j u9qfcd!2  kyu42v dmv.cst6i5fo rxhw4wvp2 1 okc8!  z aribcam0  cp-zp,!e x  agj-gb3 !om3934 k vnuo056h g7 t-6j! 8w8fncebuj-lq    inzqhw v39,  f e 9. 50 , ru3r  mbuab  6  wz dw79.av2xp . gbmy gc s6pi pra4fo9fwq k   j-ppy -3vpf   o k4hy3 -!..5s ,2 k5 j p38dtd   !i   b!fgj,nx qgif "),
              49);
    EXPECT_EQ(s.countValidWords("he bought 2 pencils, 3 erasers, and 1  pencil-sharpener."), 6);

    return EXIT_SUCCESS;
}