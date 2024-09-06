#include <unordered_set>
#include <vector>
#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Function to print the linked list
void printList(ListNode* head) {
    while (head) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

class Solution {
public:
    ListNode* modifiedList(std::vector<int>& nums, ListNode* head) {
        std::unordered_set<int> s(nums.begin(), nums.end());

        // Handle nodes at the start of the list
        while (head && s.find(head->val) != s.end()) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
        }

        // Traverse and remove remaining nodes
        ListNode* curr = head;
        while (curr && curr->next) {
            if (s.find(curr->next->val) != s.end()) {
                ListNode* temp = curr->next;
                curr->next = curr->next->next;
                delete temp;
            } else {
                curr = curr->next;
            }
        }
        return head;
    }
};

int main() {
    // Create a linked list: 1 -> 2 -> 6 -> 3 -> 4 -> 5 -> 6
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(6);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next->next = new ListNode(6);
    
    std::cout << "Original List: ";
    printList(head);

    // Values to be deleted
    std::vector<int> nums = {6, 2};

    Solution solution;
    ListNode* modified_head = solution.modifiedList(nums, head);

    std::cout << "Modified List: ";
    printList(modified_head);

    return 0;
}
