#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* ans = dummy;
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        int carry = 0;
        
        while (temp1 != NULL || temp2 != NULL) {
            int sum = carry;
            if (temp1 != NULL) {
                sum += temp1->val;
                temp1 = temp1->next;
            }
            if (temp2 != NULL) {
                sum += temp2->val;
                temp2 = temp2->next;
            }
            carry = sum / 10;
            dummy->next = new ListNode(sum % 10);
            dummy = dummy->next;
        }
        
        if (carry > 0) {
            dummy->next = new ListNode(carry);
        }
        
        return ans->next;
    }
};

// Helper function to create a linked list from a vector
ListNode* createLinkedList(const std::vector<int>& nums) {
    ListNode* dummy = new ListNode(0);
    ListNode* current = dummy;
    for (int num : nums) {
        current->next = new ListNode(num);
        current = current->next;
    }
    return dummy->next;
}

// Helper function to print a linked list
void printLinkedList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout <<endl;
}

int main() {
    Solution solution;

  vector<int> list1 = {2, 4, 3};
    vector<int> list2 = {5, 6, 4};

    // Creating linked lists from vectors
    ListNode* l1 = createLinkedList(list1);
    ListNode* l2 = createLinkedList(list2);

 
    ListNode* result = solution.addTwoNumbers(l1, l2);

    
    cout << "Sum: ";
    printLinkedList(result);

    // Cleaning up memory
    delete l1;
    delete l2;
    delete result;

    return 0;
}
