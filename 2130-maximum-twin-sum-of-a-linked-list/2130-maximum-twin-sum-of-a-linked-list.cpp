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
    int pairSum(ListNode* head) {
        vector<int> values;
        ListNode* current = head;
        while (current) {
            values.push_back(current->val);
            current = current->next;
        }
        
        int max_sum = 0;
        int n = values.size();
        for (int i = 0; i < n / 2; ++i) {
            max_sum = max(max_sum, values[i] + values[n - 1 - i]);
        }
        
        return max_sum;
    }
};
