#include <iostream>
using namespace std;


template <typename T> class LLData
{
    T data; 
    LLData* next;
    LLData() {}

public:
    LLData(T d, LLData *nxt) {
        data = d;
        next = nxt;
    }
    T getData() { return data; }
    LLData* getNext() { return next; }
    void setData(T d) { data = d; }
    void setNext(LLData* nxt) { next = nxt; }

};

template <typename T> class LinkedList{
    private:
        LLData<T>* first;
    public:
        LinkedList() { first = NULL; }
        LLData<T> *getFirst() { return first; }
        void addItem(T d) {
            first = new LLData<T>(d,first);
        } 
        void showList() {
            LLData<T> *curr = getFirst();
            while (curr != NULL) {
                cout << curr->getData() << " -> ";
                curr = curr->getNext();
            }
            cout << endl;
        }
        void addItemAtEnd(T d) {
            if (first == NULL) {
                first = new LLData<T>(d,first);
            }
            else {
                LLData<T>* curr = first;
                while (curr->getNext() != NULL) {
                    curr = curr->getNext();
                }
                curr->setNext(new LLData<T>(d,curr->getNext()));
            }
        }

};




int main() {
    LinkedList<string> myList;
    myList.addItem("hi");
    myList.addItemAtEnd("hello");
    myList.addItem("ahhh");

    myList.showList();
    return 0;
}