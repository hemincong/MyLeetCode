//
// Created by mincong.he on 2021/5/1.
//

/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        int sum = 0;
        for (auto e : employees) {
            if (e->id == id) {
                sum += e->importance;
                for (auto sub : e->subordinates) {
                    sum += getImportance(employees, sub);
                }
            }
        }
        return sum;
    }
};