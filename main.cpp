#include <iostream>
using namespace std;


template <typename T> class tempLLData
{
    T data; 
    tempLLData* next;
    tempLLData() {}

public:
    tempLLData(T d, tempLLData *nxt) {
        data = d;
        next = nxt;
    }
    T getData() { return data; }
    tempLLData* getNext() { return next; }
    void setData(T d) { data = d; }
    void setNext(tempLLData* nxt) { next = nxt; }

};

template <typename T> class tempLinkedList{
    private:
        tempLLData<T>* first;
    public:
        tempLinkedList() { first = NULL; }
        tempLLData<T> *getFirst() { return first; }
        void addItem(T d) {
            first = new tempLLData<T>(d,first);
        } 
        void showList() {
            tempLLData<T> *curr = getFirst();
            while (curr != NULL) {
                cout << curr->getData() << " -> ";
                curr = curr->getNext();
            }
            cout << endl;
        }
        void addItemAtEnd(T d) {
            if (first == NULL) {
                first = new tempLLData<T>(d,first);
            }
            else {
                tempLLData<T>* curr = first;
                while (curr->getNext() != NULL) {
                    curr = curr->getNext();
                }
                curr->setNext(new tempLLData<T>(d,curr->getNext()));
            }
        }

};




int main() {
    tempLinkedList<string> myList;
    myList.addItem("hi");
    myList.addItemAtEnd("hello");
    myList.addItem("ahhh");

    myList.showList();
    return 0;
}