//
// Created by mincong.he on 2020/12/27.
//
#include "AlgoUtils.h"

struct MyListNode {
    struct MyListNode *next;
    int value{};

    MyListNode() : next(nullptr), value(0) {
    }

    explicit MyListNode(int _value) : next(nullptr), value(_value) {
    }

    explicit MyListNode(MyListNode *_next, int _value) : next(_next), value(_value) {
    }

    ~MyListNode() {
//        if (next) {
//            //delete next;
//            next = nullptr;
//        }
    }
};

class MyLinkedList {
public:
    /** Initialize your data structure here. */
    MyLinkedList() : _root(new MyListNode()) {

    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if (!_root->next) return -1;
        MyListNode *p = _root;
        for (int i = 0; i <= index; ++i) {
            p = p->next;
            if (!p) return -1;
        }
        return p->value;
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        if (!_root->next) {
            _root->next = new MyListNode(val);
            return;
        }

        _root->next = new MyListNode(_root->next, val);
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        if (!_root->next) {
            _root->next = new MyListNode(val);
            return;
        }
        MyListNode *p = _root->next;
        MyListNode *last = _root;
        while (p) {
            p = p->next;
            last = last->next;
        }
        last->next = new MyListNode(val);
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if (index < 0) {
            addAtHead(val);
            return;
        }

        MyListNode *p = _root->next;
        MyListNode *last = _root;
        int i = 0;
        while (p && i < index) {
            p = p->next;
            last = last->next;
            i++;
        }
        // If index is greater than the length, the node will not be inserted
        if (i < index) return;
        // If index equals to the length of linked list, the node will be appended to the end of linked list.
        if (i == index) {
            last->next = new MyListNode(p, val);
            return;
        }
        if (!last->next) {
            last->next = new MyListNode(val);
            return;
        }
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if (index < 0) return;
        MyListNode *p = _root->next;
        MyListNode *last = _root;
        int i = 0;
        while (p && i < index) {
            p = p->next;
            last = last->next;
            i++;
        }
        if (i < index) return;
        if (!p) return;
        last->next = p->next;
        delete (p);
    }

private:
    MyListNode *_root;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
int main(int argc, char **argv) {
    MyLinkedList myLinkedList;
    myLinkedList.addAtHead(1);
    myLinkedList.addAtTail(3);
    myLinkedList.addAtIndex(1, 2);
    EXPECT_EQ(myLinkedList.get(1), 2);
    myLinkedList.addAtIndex(3, 4);
    EXPECT_EQ(myLinkedList.get(3), 4);
    myLinkedList.addAtIndex(-1, -1);
    EXPECT_EQ(myLinkedList.get(0), -1);
    myLinkedList.deleteAtIndex(1);
    EXPECT_EQ(myLinkedList.get(1), 2);

    MyLinkedList myLinkedList_2;
    myLinkedList_2.addAtIndex(-1, 0);
    EXPECT_EQ(myLinkedList_2.get(0), 0);
    myLinkedList_2.deleteAtIndex(-1);

    MyLinkedList myLinkedList_3;
    myLinkedList_3.addAtHead(2);
    myLinkedList_3.deleteAtIndex(1);
    myLinkedList_3.addAtHead(2);
    myLinkedList_3.addAtHead(7);
    myLinkedList_3.addAtHead(3);
    myLinkedList_3.addAtHead(2);
    myLinkedList_3.addAtHead(5);
    myLinkedList_3.addAtTail(5);
    myLinkedList_3.get(5);
    myLinkedList_3.deleteAtIndex(6);
    myLinkedList_3.deleteAtIndex(4);

    MyLinkedList myLinkedList_4;
    myLinkedList_4.addAtHead(7);
    myLinkedList_4.addAtHead(2);
    myLinkedList_4.addAtHead(1);
    myLinkedList_4.addAtIndex(3, 0);
    myLinkedList_4.deleteAtIndex(2);
    myLinkedList_4.addAtHead(6);
    myLinkedList_4.addAtTail(4);
    myLinkedList_4.get(4);
    myLinkedList_4.addAtHead(4);
    myLinkedList_4.addAtIndex(5, 0);
    myLinkedList_4.addAtHead(6);

    return EXIT_SUCCESS;
}
