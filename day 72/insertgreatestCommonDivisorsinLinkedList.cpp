#include <iostream>
using namespace std;

// Definition of ListNode structure
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// Helper function to print the linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

// Helper function to insert nodes at the end of the list
ListNode* insertAtEnd(ListNode* head, int val) {
    if (head == nullptr) return new ListNode(val);
    ListNode* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = new ListNode(val);
    return head;
}

// Function to calculate the greatest common divisor (GCD)
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

// Solution class
class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if (!head) return nullptr;
        ListNode* temp = head;
        while (temp->next) {
            // Calculate GCD between current node and next node
            ListNode* newNode = new ListNode(gcd(temp->val, temp->next->val));
            // Insert the new node between the two
            newNode->next = temp->next;
            temp->next = newNode;
            // Move to the next pair
            temp = newNode->next;
        }
        return head;
    }
};

int main() {
    // Example linked list: 12 -> 15 -> 18
    ListNode* head = nullptr;
    head = insertAtEnd(head, 12);
    head = insertAtEnd(head, 15);
    head = insertAtEnd(head, 18);

    cout << "Original List: ";
    printList(head);

    // Apply solution
    Solution solution;
    head = solution.insertGreatestCommonDivisors(head);

    cout << "List after inserting GCDs: ";
    printList(head);

    return 0;
}
