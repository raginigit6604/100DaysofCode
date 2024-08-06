#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class ListNode {
public:
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}

    // Function to print the list
    void printList() {
        ListNode* temp = this;
        while (temp) {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode* newHead = new ListNode(-1);
        ListNode* newTail = newHead;
        ListNode* ptr1 = head;
        ListNode* ptr2 = head->next;
        while (ptr1 && ptr2) {
            newTail->next = ptr2;
            ptr2 = ptr2->next;
            newTail = newTail->next;
            newTail->next = ptr1;
            newTail = newTail->next;
            ptr1 = ptr2;
            if (ptr2) {
                ptr2 = ptr2->next;
            }
            newTail->next = nullptr;
        }
        if (ptr1) {
            newTail->next = ptr1;
        }
        return newHead->next;
    }
};

int main() {
    // Create a sample linked list: 1 -> 2 -> 3 -> 4
    ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4))));

    cout << "Original list: ";
    head->printList();

    // Swap nodes in pairs
    Solution sol;
    ListNode* newHead = sol.swapPairs(head);

    cout << "List after swapping pairs: ";
    newHead->printList();

    return 0;
}
