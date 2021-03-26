//
// Created by mincong.he on 2019/9/24.
//

#ifndef LEETCODE_ALGO_UTILS_H
#define LEETCODE_ALGO_UTILS_H

#include <stack>
#include <vector>
#include <queue>
#include <ostream>
#include <iostream>
#include <string>

#define EXPECT_EQ(ret, expect) \
    if ((expect) != (ret)) \
        std::cout << __FILE__ << ":" << __LINE__ << " ret:" << ret << " expect:" << expect << std::endl;

#define EXPECT_TRUE(stetment) \
    if ((stetment) != (true)) \
        std::cout << __FILE__ << ":" << __LINE__ << " ret: false expect: true" << std::endl;

#define EXPECT_FALSE(stetment) \
    if ((stetment) == (true)) \
        std::cout << __FILE__ << ":" << __LINE__ << " ret: true expect: false" << std::endl;


template<class Container, class Stream>
Stream &printOneValueContainer
        (Stream &outputstream, const Container &container) {
    typename Container::const_iterator beg = container.begin();

    outputstream << "[";

    while (beg != container.end()) {
        outputstream << " " << *beg++;
    }

    outputstream << " ]";

    return outputstream;
}

template<class Type, class Container>
const Container &container
        (const std::stack<Type, Container> &stack) {
    struct HackedStack : private std::stack<Type, Container> {
        static const Container &container
                (const std::stack<Type, Container> &stack) {
            return stack.*&HackedStack::c;
        }
    };

    return HackedStack::container(stack);
}

template<class Type, class Container>
const Container &container
        (const std::queue<Type, Container> &queue) {
    struct HackedQueue : private std::queue<Type, Container> {
        static const Container &container
                (const std::queue<Type, Container> &queue) {
            return queue.*&HackedQueue::c;
        }
    };

    return HackedQueue::container(queue);
}

template<class Type, template<class c, class Container = std::deque<Type> > class Adapter, class Stream>
Stream &operator<<
        (Stream &outputstream, const Adapter<Type> &adapter) {
    return printOneValueContainer(outputstream, container(adapter));
}

template<class T>
void printArray(std::vector<T> ret) {
    for (const auto &r : ret) {
        std::cout << r << " ";
    }
}

template<class T>
void printArrayErr(std::vector<T> ret) {
    for (const auto &r : ret) {
        std::cerr << r << " ";
    }
}

template<class T>
void printTwoArrayErr(std::vector<T> ret, std::vector<T> expect) {
    std::cerr << "   ret : ";
    printArrayErr(ret);
    std::cerr << std::endl << "expect : ";
    printArrayErr(expect);
    std::cerr << std::endl;
}

template<class T>
bool assertArray(std::vector<T> ret, std::vector<T> expect) {
    if (ret.size() != expect.size()) {
        std::cerr << "size not match" << std::endl;
        printTwoArrayErr(ret, expect);

        return false;
    }

    auto iter_ret = ret.begin();
    auto iter_expect = expect.begin();
    while (iter_ret != ret.end() && iter_expect != expect.end()) {
        std::cout << *iter_ret << " ";
        if (*iter_ret != *iter_expect) {
            printTwoArrayErr(ret, expect);
            return false;
        }
        iter_ret++;
        iter_expect++;
    }
    std::cout << std::endl;
    return true;
}


template<class T>
void printMatrix(std::vector<std::vector<T>> m) {
    for (const auto &r : m) {
        std::cout << "[ ";
        printArray(r);
        std::cout << "]" << std::endl;
    }
    std::cout << std::endl;
}

template<class T>
struct TreeNode {
    T val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(T x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode *build_list_node(const std::vector<int> &input) {
    if (input.empty()) return nullptr;

    auto *root = new ListNode(input[0]);
    auto *p = root;
    for (int i = 1; i < input.size(); ++i) {
        auto *tmp = new ListNode(input[i]);
        p->next = tmp;
        p = p->next;
    }
    return root;
}

std::vector<int> build_vector(const ListNode *root) {
    std::vector<int> ret;

    auto p = root;
    while (p) {
        ret.push_back(p->val);
        p = p->next;
    }
    return ret;
}

void release_list_node(ListNode *root) {
    auto p = root;
    while (p) {
        auto tmp = p->next;
        delete p;
        p = tmp;
    }
}

#endif //LEETCODE_ALGO_UTILS_H
