# CS2_HW2

## Introduction
I wrote some simple code for a Linked List of integers, shown here (including some simple testing).

#include <iostream>
using namespace std;

class LLData {
private:
    int data;
    LLData *next;
    LLData() {}
public:
    LLData(int d, LLData *nxt) {
        data = d;
        next = nxt;
    }
    int getData() { return data; }
    LLData* getNext() { return next; }
    void setData(int d) { data = d; }
    void setNext(LLData* nxt) { next = nxt; }
};
class LinkedList {
private:
    LLData* first;
public:
    LinkedList() { first = NULL; }
    LLData *getFirst() { return first; }
    void addItem(int d) {
        first = new LLData(d,first);
    }
    void showList() {
        LLData *curr = getFirst();
        while (curr != NULL) {
            cout << curr->getData() << " -> ";
            curr = curr->getNext();
        }
        cout << endl;
    }
    void addItemAtEnd(int d) {
        if (first == NULL) {
            first = new LLData(d,first);
        }
        else {
            LLData* curr = first;
            while (curr->getNext() != NULL) {
                curr = curr->getNext();
            }
            curr->setNext(new LLData(d,curr->getNext()));
        }
    }
};

int main() {
    LinkedList myList;
    myList.addItem(1);
    myList.addItemAtEnd(2);
    myList.addItem(3);
    myList.addItemAtEnd(4);
    myList.showList();
    myList.addItem(5);
    myList.addItemAtEnd(6);
    myList.showList();
    return 0;
}

But I would like to have this code do other types of Linked Lists without having to implement multiple classes.  But I am having problems doing so.  So, I want you to re-implement the two classes to be two template classes.  Then I want you to do the testing of the class that is there for integers, but then make a copy of the testing and set it up to test for a Linked List of string values.

## What to Submit
Once you have completed your program submit your code via the canvas interface as a single file. Make sure that you include the names and ID#s of all of the people in your group.