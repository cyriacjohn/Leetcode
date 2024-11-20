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
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) return head;  // Edge case: empty list or single node

        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenHead = even;  // Save the head of the even list

        while (even && even->next) {
            odd->next = even->next;  // Link odd nodes
            odd = odd->next;

            even->next = odd->next;  // Link even nodes
            even = even->next;
        }

        odd->next = evenHead;  // Append the even list after the odd list
        return head;
    }
};

// Helper functions for testing
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}