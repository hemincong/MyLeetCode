#include <vector>
#include <unordered_map>
#include <string>
#include "AlgoUtils.h"

using namespace std;

class TimeMap {
public:
    /** Initialize your data structure here. */
    TimeMap() {

    }

    void set(string key, string value, int timestamp) {
        m[key].emplace_back(make_pair(timestamp, value));
    }

    string get(string key, int timestamp) {
        auto k_iter = m.find(key);
        if (k_iter == m.end()) return "";
        auto &v = k_iter->second;
        if (v.empty() || v[0].first > timestamp) return "";
        int l = 0;
        int r = v.size() - 1;
        while (l < r) {
            int mid = (l + r + 1) / 2;
            if (v[mid].first <= timestamp) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        return v[l].second;
    }

private:
    unordered_map<string, vector<pair<int, string>>> m;
};


int main(int argc, char **argv) {
    auto *obj = new TimeMap();
    obj->set("foo", "bar", 1);
    EXPECT_EQ(obj->get("foo", 1), "bar");
    EXPECT_EQ(obj->get("foo", 3), "bar");
    obj->set("foo", "bar2", 4);
    EXPECT_EQ(obj->get("foo", 4), "bar2");
    EXPECT_EQ(obj->get("foo", 5), "bar2");
    delete obj;

    auto *obj_2 = new TimeMap();
    obj_2->set("love", "high", 10);
    obj_2->set("love", "low", 20);
    EXPECT_EQ(obj_2->get("love", 5), "");
    EXPECT_EQ(obj_2->get("love", 10), "high");
    EXPECT_EQ(obj_2->get("love", 15), "high");
    EXPECT_EQ(obj_2->get("love", 20), "low");
    EXPECT_EQ(obj_2->get("love", 25), "low");
    delete obj_2;
    return EXIT_SUCCESS;
}