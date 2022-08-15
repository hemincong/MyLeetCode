//
// Created by mincong.he on 2022/8/15.
//
#include "AlgoUtils.h"

class MyCircularDeque {
public:
    MyCircularDeque(int k) :
            _buff(k, 0),
            _size(0),
            _front_index(0),
            _tail_index(k - 1) {
    }

    bool insertFront(int value) {
        if (isFull()) return false;
        if (_front_index == 0) {
            _front_index = _buff.size() - 1;
        } else {
            _front_index--;
        }
        _buff[_front_index] = value;
        _size++;
        return true;
    }

    bool insertLast(int value) {
        if (isFull()) return false;
        if (_tail_index == _buff.size() - 1) {
            _tail_index = 0;
        } else {
            _tail_index++;
        }
        _buff[_tail_index] = value;
        _size++;
        return true;
    }

    bool deleteFront() {
        if (isEmpty()) return false;
        if (_front_index == _buff.size() - 1) {
            _front_index = 0;
        } else {
            _front_index++;
        }
        _size--;
        return true;
    }

    bool deleteLast() {
        if (isEmpty()) return false;
        if (_tail_index == 0) {
            _tail_index = _buff.size() - 1;
        } else {
            _tail_index--;
        }
        _size--;
        return true;
    }

    int getFront() {
        if (_size == 0) return -1;
        return _buff[_front_index];
    }

    int getRear() {
        if (_size == 0) return -1;
        return _buff[_tail_index];
    }

    bool isEmpty() {
        return _size == 0;
    }

    bool isFull() {
        return _size == _buff.size();
    }

private:
    std::vector<int> _buff;
    unsigned int _front_index;
    unsigned int _tail_index;
    size_t _size;
};

int main(int argc, char **argv) {
/**
 * Your MyCircularDeque object will be instantiated and called as such:
 */
    auto *myCircularDeque = new MyCircularDeque(3);
    EXPECT_TRUE(myCircularDeque->insertLast(1));  // return True
    EXPECT_TRUE(myCircularDeque->insertLast(2));  // return True
    EXPECT_TRUE(myCircularDeque->insertFront(3)); // return True
    EXPECT_FALSE(myCircularDeque->insertFront(4)); // return False, the queue is full->
    EXPECT_EQ(myCircularDeque->getRear(), 2);      // return 2
    EXPECT_TRUE(myCircularDeque->isFull());       // return True
    EXPECT_TRUE(myCircularDeque->deleteLast());   // return True
    EXPECT_TRUE(myCircularDeque->insertFront(4)); // return True
    EXPECT_EQ(myCircularDeque->getFront(), 4);     // return 4
    delete (myCircularDeque);
    myCircularDeque = nullptr;

    myCircularDeque = new MyCircularDeque(8);
    EXPECT_TRUE(myCircularDeque->insertFront(5));  // return True
    EXPECT_EQ(myCircularDeque->getFront(), 5);  // return True
    EXPECT_FALSE(myCircularDeque->isEmpty());  // return True
    EXPECT_TRUE(myCircularDeque->deleteFront()); // return True
    EXPECT_TRUE(myCircularDeque->insertLast(3)); // return False, the queue is full->
    EXPECT_EQ(myCircularDeque->getRear(), 3);      // return 2
    EXPECT_TRUE(myCircularDeque->insertLast(7));       // return True
    EXPECT_TRUE(myCircularDeque->insertFront(7));   // return True
    EXPECT_TRUE(myCircularDeque->deleteLast()); // return True
    EXPECT_TRUE(myCircularDeque->insertLast(4));     // return 4
    EXPECT_FALSE(myCircularDeque->isEmpty());     // return 4
    delete (myCircularDeque);
    myCircularDeque = nullptr;

    myCircularDeque = new MyCircularDeque(4);
    EXPECT_TRUE(myCircularDeque->insertFront(9));  // return True
    EXPECT_TRUE(myCircularDeque->deleteLast());  // return True
    EXPECT_EQ(myCircularDeque->getRear(), -1);  // return True
    EXPECT_EQ(myCircularDeque->getFront(), -1); // return True
    EXPECT_EQ(myCircularDeque->getFront(), -1); // return False, the queue is full->
    EXPECT_FALSE(myCircularDeque->deleteFront());      // return 2
    EXPECT_TRUE(myCircularDeque->insertFront(6));       // return True
    EXPECT_TRUE(myCircularDeque->insertLast(5));   // return True
    EXPECT_TRUE(myCircularDeque->insertFront(9)); // return True
    EXPECT_EQ(myCircularDeque->getFront(), 9);     // return 4
    EXPECT_TRUE(myCircularDeque->insertFront(6));     // return 4

    return EXIT_SUCCESS;
}
