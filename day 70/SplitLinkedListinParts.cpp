#include<bits/stdc++.h>
using namespace std;

// Define the ListNode structure
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    int countNodes(ListNode* head) {
        int count = 0;
        while (head) {
            count++;
            head = head->next;
        }
        return count;
    }

    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int totalNodes = countNodes(head);
        int baseSize = totalNodes / k, extraNodes = totalNodes % k;
        vector<ListNode*> result(k, nullptr);
        ListNode* current = head, *prev = nullptr;

        for (int i = 0; i < k; ++i) {
            result[i] = current;
            int currentPartSize = baseSize + (i < extraNodes ? 1 : 0);
            for (int j = 0; j < currentPartSize; ++j) {
                prev = current;
                if (current) current = current->next;
            }
            if (prev) prev->next = nullptr;
        }
        return result;
    }
};

// Main function to demonstrate the solution
int main() {
    // Example input: Create a linked list and split it
    Solution solution;
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    int k = 5;
    
    vector<ListNode*> parts = solution.splitListToParts(head, k);

    // Output the result
    for (auto part : parts) {
        while (part) {
            cout << part->val << " ";
            part = part->next;
        }
        cout << " | ";
    }
    return 0;
}
