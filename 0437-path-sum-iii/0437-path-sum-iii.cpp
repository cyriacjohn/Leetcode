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
    int pathSum(TreeNode* root, int targetSum) {
         unordered_map<long long, int> prefixSumCount;
        prefixSumCount[0] = 1; 
        return dfs(root, 0, targetSum, prefixSumCount);
    }

    private:
    int dfs(TreeNode* node, long long currentSum, int targetSum, unordered_map<long long, int>& prefixSumCount) {
        if (!node) return 0; 
        
        currentSum += node->val;

        int count = prefixSumCount[currentSum - targetSum];

        prefixSumCount[currentSum]++;
        
        count += dfs(node->left, currentSum, targetSum, prefixSumCount);
        count += dfs(node->right, currentSum, targetSum, prefixSumCount);
        
        prefixSumCount[currentSum]--;
        
        return count;
    }

};