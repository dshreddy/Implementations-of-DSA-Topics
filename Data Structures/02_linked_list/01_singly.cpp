#include <iostream>
using namespace std;

struct ListNode {
public:
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int val) : val(val), next(nullptr) {}
};

class MyLinkedList {
private:
    ListNode *head = nullptr;
    ListNode *tail = nullptr;
    int size = 0;

    // O(1)
    // helper, caller updates size
    void addAtHead(int val) {
        ListNode *newN = new ListNode(val);
        if(head) {
            newN->next = head;
            head = newN;
        } else {
            head = newN;
            tail = head;
        }
    }
    
    // O(1)
    // helper, caller updates size
    void addAtTail(int val) {
        ListNode *newN = new ListNode(val);
        if(tail) {
            tail->next = newN;
            tail = newN;
        } else {
            head = newN;
            tail = head;
        }
    }

    // O(1)
    // helper, caller updates size
    void deleteAtHead() {
        ListNode *temp = head;
        if(head == tail) {
            head = nullptr;
            tail = nullptr;
        } else {
            head = head->next;
        }
        delete temp;
    }

public:

    // O(1)
    int getSize() {
        return size;
    }

    // O(n)
    int get(int index) {
        if(index < 0 || index >= size) return -1;

        ListNode *temp = head;
        while(index--) temp = temp->next;
        return temp->val;
    }

    // O(n)
    void print() {
        ListNode *temp = head;
        while(temp) {
            cout << temp->val << "\t";
            temp = temp->next;
        }
        cout << endl;
    }
    
    // O(n)
    void addAtIndex(int index, int val) {
        if(index < 0 || index > size) return;
        if(index == 0) addAtHead(val);
        else if(index == size) addAtTail(val);
        else {
            ListNode *p = nullptr, *q = head;
            while(index--) {
                p = q;
                q = q->next;
            }

            ListNode *newN = new ListNode(val);

            p->next = newN;
            newN->next = q;
        }
        size++;
    }
    
    // O(n)
    void deleteAtIndex(int index) {

        if(index < 0 || index >= size) return;
        if(index == 0) deleteAtHead();
        else {
            ListNode *p = nullptr, *q = head;
            while(index--) {
                p = q;
                q = q->next;
            }

            p->next = q->next;
            if(q == tail) tail = p;
            delete q;
        }
        size--;
    }

    ~MyLinkedList() {
        while(head) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main()
{

    MyLinkedList list;
    list.addAtIndex(0, 0);
    list.addAtIndex(1, 1);
    list.addAtIndex(2, 2);
    list.addAtIndex(3, 3);
    list.print();


    // Insert at head
    list.addAtIndex(0, -1);
    list.print();

    // Insert at middle
    list.addAtIndex(2, -2);
    list.print();

    // Insert at end
    list.addAtIndex(list.getSize(), -3);
    list.print();

    // Remove at head
    list.deleteAtIndex(0);
    list.print();

    // Remove at middle
    list.deleteAtIndex(1);
    list.print();

    // Remove at end
    list.deleteAtIndex(list.getSize() - 1);
    list.print();
}