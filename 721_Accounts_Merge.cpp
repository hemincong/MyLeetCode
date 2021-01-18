//
// Created by mincong.he on 2021/1/18.
//
#include "AlgoUtils.h"

#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
        vector<vector<string>> ret;
        if (accounts.empty()) return ret;

        std::map<string, int> email_to_index;
        std::map<string, string> email_to_name;
        std::map<int, vector<string>> root_to_emails;

        int email_index = 0;
        for (const auto &a: accounts) {
            const auto &name = a[0];

            for (int i = 1; i < a.size(); ++i) {
                if (email_to_index.find(a[i]) == email_to_index.end()) {
                    email_to_index[a[i]] = email_index;
                    email_to_name[a[i]] = name;
                    email_index++;
                }
            }
        }

        for (int i = 0; i < email_index; ++i) {
            _parent.push_back(i);
        }

        for (const auto &a: accounts) {
            const auto &name = a[0];
            int first_index = email_to_index.find(a[1])->second;
            for (int i = 2; i < a.size(); ++i) {
                int next_index = email_to_index.find(a[i])->second;
                _union(first_index, next_index);
            }
        }

        for (const auto &e_i_pair : email_to_index) {
            const auto &email = e_i_pair.first;
            const auto &index = e_i_pair.second;
            const auto root_i = find(index);
            root_to_emails[root_i].push_back(email);
        }

        for (const auto &i_es_pair : root_to_emails) {
            vector<string> one_record;
            auto emails = i_es_pair.second;
            sort(emails.begin(), emails.end());
            auto first_email = emails[0];
            auto name = email_to_name.find(first_email)->second;
            one_record.push_back(name);
            for (const auto &e: emails) {
                one_record.push_back(e);
            }
            ret.push_back(one_record);
        }

        return ret;
    }

private:
    void _union(int p, int q) {
        auto p_root = find(p);
        auto q_root = find(q);

        if (p_root == q_root) return;

        _parent[p_root] = q_root;
    }

    int find(int p) {
        if (_parent[p] == p) return p;

        if (_parent[p] != p) {
            _parent[p] = find(_parent[p]);
        }

        return _parent[p];
    }

    vector<int> _parent;
};

int main(int argc, char **argv) {
    Solution s;
    vector<vector<string>> test_case_1{{"John", "johnsmith@mail.com", "john00@mail.com"},
                                       {"John", "johnnybravo@mail.com"},
                                       {"John", "johnsmith@mail.com", "john_newyork@mail.com"},
                                       {"Mary", "mary@mail.com"}};
    // output:
    //[
    //  ['Mary'，'mary@mail.com']，
    //  ['John'，'johnnybravo@mail.com']，
    //  ['John'，'john00@mail.com'，'john_newyork@mail.com'，'johnsmith@mail.com']]
    //]

    printMatrix(s.accountsMerge(test_case_1));
    return EXIT_SUCCESS;
}