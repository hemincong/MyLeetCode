//
// Created by mincong.he on 2019/9/24.
//

#ifndef LEETCODE_ALGO_UTILS_H
#define LEETCODE_ALGO_UTILS_H

#include <stack>
#include <queue>
#include <ostream>
#include <iostream>
#include <string>

#define EXPECT_EQ(ret, expect) \
    if ((expect) != (ret)) \
        std::cout << __FILE__ << ":" << __LINE__ << "ret:" << std::to_string(ret) << " expect:" << std::to_string(expect) << std::endl;


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

template<class Type, template<class c, class Container = std::deque<Type> > class Adapter, class Stream >
Stream &operator<<
        (Stream &outputstream, const Adapter<Type> &adapter) {
    return printOneValueContainer(outputstream, container(adapter));
}

#endif //LEETCODE_ALGO_UTILS_H
