#include <iostream>
#include <vector>
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
    vector<vector<int>> spiralMatrix(int n, int m, ListNode* head) 
    {
        // Create a matrix of n x m with values filled with -1.
        vector<vector<int>> result(n, vector<int>(m, -1));
        int i = 0, j = 0;
        // If head reaches NULL pointer break out from the loop, and return the spiral matrix.
        while (head != NULL)
        {
            if (j < m)
            {
                while (head != NULL && j < m && result[i][j] == -1)
                {
                    result[i][j] = head->val;
                    head = head->next;
                    j++;
                }
                if (head == NULL)
                    break;
                i++;
                j--;
            }
            if (i < n)
            {
                while (head != NULL && i < n && result[i][j] == -1)
                {
                    result[i][j] = head->val;
                    head = head->next;
                    i++;
                }
                i--;
                j--;
            }
            if (j >= 0)
            {
                while (head != NULL && j >= 0 && result[i][j] == -1)
                {
                    result[i][j] = head->val;
                    head = head->next;
                    j--;
                }
                j++;
                i--;
            }
            if (i >= 0)
            {
                while (head != NULL && i >= 0 && result[i][j] == -1)
                {
                    result[i][j] = head->val;
                    head = head->next;
                    i--;
                }
                i++;
                j++;
            }
            n--;
            m++;
        }
        // Rest values are itself -1.
        return result;
    }
};

// Helper function to create a linked list from a vector of values
ListNode* createLinkedList(const vector<int>& values) {
    if (values.empty()) return nullptr;
    ListNode* head = new ListNode(values[0]);
    ListNode* current = head;
    for (size_t i = 1; i < values.size(); ++i) {
        current->next = new ListNode(values[i]);
        current = current->next;
    }
    return head;
}

// Helper function to print a 2D matrix
void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int value : row) {
            cout << value << " ";
        }
        cout << endl;
    }
}

int main() {
    // Example input: create a linked list with values 1, 2, 3, ..., 12
    vector<int> values = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    ListNode* head = createLinkedList(values);

    // Matrix dimensions
    int n = 3, m = 4;

    // Call the solution function
    Solution solution;
    vector<vector<int>> result = solution.spiralMatrix(n, m, head);

    // Print the result matrix
    printMatrix(result);

    // Free the linked list memory
    ListNode* temp;
    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }
    return 0;
}