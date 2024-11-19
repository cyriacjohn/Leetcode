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

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        // Edge case: If the list has only one node, return nullptr
        if (!head || !head->next) {
            return nullptr;
        }
        
        // Two-pointer approach
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;
        
        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // Remove the middle node
        prev->next = slow->next;
        delete slow;  // Free memory for the middle node
        
        return head;
    }
};

// Helper function to build a linked list from a vector
ListNode* buildLinkedList(const vector<int>& values) {
    if (values.empty()) return nullptr;
    ListNode* head = new ListNode(values[0]);
    ListNode* current = head;
    for (size_t i = 1; i < values.size(); ++i) {
        current->next = new ListNode(values[i]);
        current = current->next;
    }
    return head;
}

// Helper function to print the linked list
void printLinkedList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

// Helper function to free the entire linked list
void freeList(ListNode*& head) {
    ListNode* current = head;
    while (current) {
        ListNode* temp = current;
        current = current->next;
        delete temp;  // Free memory for the current node
    }
    head = nullptr;  // Set head to nullptr to avoid dangling pointers
}