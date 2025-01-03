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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
         vector<int> leaves1, leaves2;
        
       
        getLeaves(root1, leaves1);
        getLeaves(root2, leaves2);
        
        
        return leaves1 == leaves2;
    }
    private:
    void getLeaves(TreeNode* node, vector<int>& leaves) {
        if (!node) return; 
        
        if (!node->left && !node->right) {
            leaves.push_back(node->val);
            return;
        }
        
        getLeaves(node->left, leaves);
        getLeaves(node->right, leaves);
    }
};