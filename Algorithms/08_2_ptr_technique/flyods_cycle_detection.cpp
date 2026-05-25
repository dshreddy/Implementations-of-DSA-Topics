#include<iostream>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

/*
    - If no cycle 
        - Then either fast or fast->next becomes null at some point
    - If there's a cycle
        - Let's say by the time slow reaches the start of cycle fast is at x distance from start
        - Let's say cycle length (num nodes) = c
        - Distance between fast & slow is c-x
        - Since both are inside the cycle, with every iteration the distance between slow & fast decreases by 1 
        - So after c-x iterations the distance between them is bound to become 0

    Example : 
             sl   fa
    1 -> 2 -> 3 -> 4
              ^    |
              |    v
              8    5
              ^    |
              |    v
              7 <- 6 
    - Cycle len = 6
    - Distance between slow & fast = 1
    - Distance between fast & slow = 5   
*/
bool hasCycle(ListNode *head) {
    ListNode *fast = head, *slow = head;

    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast) return true;
    }
    return false;
}

/*
    - Let's say, slow & fast meet at x distance from start of cycle
    - Let's say cycle length (num nodes) = c
    - Let's say distance between head & start of cycle = d
    - distance_travelled_by_fast = 2 * distance_travelled_by_slow
    => (d+c+x) = 2 * (d+x)
    => c = d + x
    => c - x = d
    Example : 
             sl   fa
    1 -> 2 -> 3 -> 4
              ^    |
              |    v
              8    5
              ^    |
              |    v
              7 <- 6 
    - Cycle len = 6
    - Distance between slow & fast = 1
    - Distance between fast & slow = 5   
*/
ListNode * cycleStart(ListNode *head) {
    ListNode *fast = head, *slow = head;
    bool hasCycle = false;

    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast) {
            hasCycle = true;
            break;
        }
    }

    if(!hasCycle) return nullptr;

    ListNode *slow2 = head;
    while(slow != slow2) {
        slow = slow->next;
        slow2 = slow2->next;
    }

    return slow;
}

// Given a linked list without cycles, return the middle node. If there are even nodes, return the second middle node.
ListNode* middleNode(ListNode* head) {
    ListNode *slow = head, *fast = head;
    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

int main() {
    // Given a sorted array and a target sum, find if there exists a pair in the array whose sum is equal to the given target.
    // Assume there is exactly one solution, and you may not use the same element twice.
    vector<int> v = {-1, 0, 1, 2, 3};
    int target = 2;
    pair<int, int> ans = target_sum(v, target);
    if(ans.first != -1) cout << "Pair found at indices: " << ans.first << " and " << ans.second << endl;
    else cout << "No pair found." << endl;
    return 0;
}