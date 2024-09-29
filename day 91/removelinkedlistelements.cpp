#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (!head) {
            return NULL;
        }
        // Move head if it contains the value to remove
        while (head && head->val == val) {
            head = head->next;
        }
        ListNode* temp = head;
        // Traverse the list and remove matching nodes
        while (temp) {
            if (temp->next && temp->next->val == val) {
                temp->next = temp->next->next;
            } else {
                temp = temp->next;
            }
        }
        return head;
    }
};

// Helper function to create a new node
ListNode* createNode(int val) {
    return new ListNode(val);
}

// Helper function to print the linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

// Main function
int main() {
    // Creating the linked list: 1 -> 2 -> 6 -> 3 -> 4 -> 5 -> 6
    ListNode* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(6);
    head->next->next->next = createNode(3);
    head->next->next->next->next = createNode(4);
    head->next->next->next->next->next = createNode(5);
    head->next->next->next->next->next->next = createNode(6);

    // Print original list
    cout << "Original List: ";
    printList(head);

    // Value to remove
    int val = 6;

    // Solution object
    Solution solution;
    // Remove elements with value 6
    head = solution.removeElements(head, val);

    // Print modified list
    cout << "Modified List after removing " << val << ": ";
    printList(head);

    return 0;
}
