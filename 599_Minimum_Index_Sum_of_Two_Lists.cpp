#include <vector>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        vector<string> ret;
        unordered_map<string, int> fav_1;
        for (int i = 0; i < list1.size(); ++i) {
            fav_1.insert(make_pair(list1[i], i));
        }
        int min_scroe = INT_MAX;
        for (int i = 0; i < list2.size(); ++i) {
            auto fav_1_item = fav_1.find(list2[i]);
            if (fav_1_item == fav_1.end()) continue;
            auto fav_1_score = fav_1_item->second;
            if (min_scroe > fav_1_score + i) {
                min_scroe = fav_1_score + i;
                ret.clear();
                ret.push_back(list2[i]);
            } else if (min_scroe == fav_1_score + i) {
                ret.push_back(list2[i]);
            }
        }
        return ret;
    }
};

int main(int argc, char **argv) {
    Solution s;
    return EXIT_SUCCESS;
}