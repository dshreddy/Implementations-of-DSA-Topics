#include<iostream>
using namespace std;

struct ListNode{
public:

    int val;
    ListNode* next;
    ListNode* prev;

    ListNode(): val(0), next(nullptr) {}
    ListNode(int val): val(val), next(nullptr) {}
};

class DoublyLinkedList{
private:

    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    int size = 0;

public:

    int getSize() {
        return size;
    }
    
    // Assuming 0 based indexing
    void insert(int index, int val) {
        
        // Invalid cases
        if(index < 0 || index > size) throw std::out_of_range("Index out of bounds");

        size++;
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* newNode = new ListNode(val);

        for(int i = 0; i < index; i++) {
            prev = curr;
            curr = curr->next;
        }

        // prev null implies we're inserting at start, so update head and if needed update tail
        if(prev == nullptr) {
            if(head) {
                newNode->next = head;
                head->prev = newNode;
                head = newNode;
            } else {
                // Empty list case
                head = newNode;
                tail = head;
            }
            return;
        } 

        prev->next = newNode;
        newNode->prev = prev;
        newNode->next = curr;
        if(curr) curr->prev = newNode;
        else tail = newNode; // curr null implies we're inserting at end, so update tail
    }

    // Assuming 0 based indexing
    void remove(int index) {
        // Invalid cases
        if(index < 0 || index >= size) throw std::out_of_range("Index out of bounds");

        size--;
        ListNode* prev = nullptr;
        ListNode* curr = head;

        for(int i = 0; i < index; i++) {
            prev = curr;
            curr = curr->next;
        }

        // prev null implies we're deleting at start, so update head and if needed update tail 
        if(prev == nullptr) {
            if(head->next) {
                head = head->next;
                head->prev = nullptr;
            } else {
                // Single element case
                head = nullptr;
                tail = nullptr;
            }
            delete curr;
            return;
        }
        
        prev->next = curr->next;
        if(curr->next) curr->next->prev = prev;
        else tail = prev; // curr->next null implies we're deleteing the current tail, so update tail
        delete curr;
    }

    void print() {
        ListNode* temp = head;
        while(temp) {
            cout<<temp->val<<"\t";
            temp = temp->next;
        }
        cout<<"\n";
    }

    ~DoublyLinkedList()
    {
        ListNode *curr = head;
        while (curr)
        {
            ListNode *temp = curr;
            curr = curr->next;
            delete temp;
        }
    }
};


int main() {

    DoublyLinkedList list;
    list.insert(0, 0);
    list.insert(1, 1);
    list.insert(2, 2);
    list.insert(3, 3);
    list.print();

    // Insert at head
    list.insert(0, -1);
    list.print();

    // Insert at middle
    list.insert(2, -2);
    list.print();

    // Insert at end
    list.insert(list.getSize(), -3);
    list.print();

    // Remove at head
    list.remove(0);
    list.print();

    // Remove at middle
    list.remove(2);
    list.print(); 

    // Remove at end
    list.remove(list.getSize()-1);
    list.print();
}