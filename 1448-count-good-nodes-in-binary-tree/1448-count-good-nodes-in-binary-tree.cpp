/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int countGoodNodes(TreeNode* root, int maxVal) {
        if (!root) return 0;

        
        int isGood = root->val >= maxVal ? 1 : 0;

        maxVal = max(maxVal, root->val);

     
        return isGood + countGoodNodes(root->left, maxVal) + countGoodNodes(root->right, maxVal);
    }

    int goodNodes(TreeNode* root) {
        return countGoodNodes(root, root->val); 
    }
};