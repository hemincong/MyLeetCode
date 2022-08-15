#include <utility>
#include <vector>
#include "AlgoUtils.h"

using namespace std;

#define is_vowel(c) \
    (((c) == 'a') || ((c) == 'e') || ((c) == 'i') || ((c) == 'o') || ((c) == 'u') || ((c) == 'A') || ((c) == 'E') || ((c) == 'I') || ((c) == 'O') || ((c) == 'U'))

class Solution {
public:
    string toGoatLatin(string sentence) {
        std::string delimiter = " ";
        std::string s = std::move(sentence);
        size_t start = 0;
        int index = 0;
        std::string token;
        vector<char> buff;

        auto end = s.find(delimiter);
        while (end != std::string::npos) {
            token = s.substr(start, end - start);

            processString(buff, token, ++index);
            buff.push_back(' ');
            start = end + delimiter.length();
            end = s.find(delimiter, start);
        }
        processString(buff, s.substr(start, end), index + 2);
        buff[buff.size() - 1] = '\0';
        return {buff.data()};
    }

private:
    void processString(vector<char> &buff, const string &token, int index) {
        int start;
        if (is_vowel(token[0])) {
            start = 0;
        } else {
            start = 1;
        }
        for (int i = start; i < token.size(); ++i) {
            buff.push_back(token[i]);
        }
        if (!is_vowel(token[0])) {
            buff.push_back(token[0]);
        }
        buff.push_back('m');
        buff.push_back('a');
        for (int i = 0; i < index; ++i) {
            buff.push_back('a');
        }
    }
};

int main(int argc, char **argv) {
    Solution s;
    EXPECT_EQ(s.toGoatLatin("I"), "Imaa");
    EXPECT_EQ(s.toGoatLatin("I speak Goat Latin"), "Imaa peaksmaaa oatGmaaaa atinLmaaaaa");
    EXPECT_EQ(s.toGoatLatin("The quick brown fox jumped over the lazy dog"),
              "heTmaa uickqmaaa rownbmaaaa oxfmaaaaa umpedjmaaaaaa overmaaaaaaa hetmaaaaaaaa azylmaaaaaaaaa ogdmaaaaaaaaaa");
    return EXIT_SUCCESS;
}