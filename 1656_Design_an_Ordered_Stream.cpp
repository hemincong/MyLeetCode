//
// Created by mincong.he on 2022/8/16.
//
#include <utility>
#include <vector>
#include <string>
#include "AlgoUtils.h"

using namespace std;

class OrderedStream {
public:
    OrderedStream(int n) : ptr(1), _buff(n + 1) {
    }

    vector<string> insert(int idKey, string value) {
        _buff[idKey] = std::move(value);
        vector<string> ret;

        for (int i = ptr; i < _buff.size(); ++i) {
            if (!_buff[i].empty()) {
                ret.push_back(_buff[i]);
                ptr++;
            } else {
                break;
            }
        }
        return ret;
    }

private:
    int ptr;
    vector<string> _buff;
};


int main(int argc, char **argv) {
/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */
    auto *obj = new OrderedStream(5);
    vector<string> ret_empty;
    vector<string> param_0 = obj->insert(3, "ccccc");
    assertArray(param_0, ret_empty);

    vector<string> ret_1{"aaaaa"};
    auto param_1 = obj->insert(1, "aaaaa");
    assertArray(param_1, ret_1);

    vector<string> ret_2{"bbbbb", "ccccc"};
    vector<string> param_2 = obj->insert(2, "bbbbb");
    assertArray(param_2, ret_2);

    vector<string> param_3 = obj->insert(5, "eeeee");
    assertArray(param_3, ret_empty);

    vector<string> ret_4{"ddddd", "eeeee"};
    vector<string> param_4 = obj->insert(4, "ddddd");
    assertArray(param_4, ret_4);
    return EXIT_SUCCESS;
}