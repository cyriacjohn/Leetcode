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
        int maxLevelSum(TreeNode* root) {
        if (!root) return 0;

        queue<TreeNode*> q;
        q.push(root);

        int maxSum = INT_MIN;
        int maxLevel = 1;
        int currentLevel = 1;

        while (!q.empty()) {
            int levelSize = q.size();
            int levelSum = 0;

            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = q.front();
                q.pop();
                levelSum += node->val;

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            if (levelSum > maxSum) {
                maxSum = levelSum;
                maxLevel = currentLevel;
            }

            currentLevel++;
        }

        return maxLevel;
    }
};


TreeNode* buildTree(vector<int> vals) {
    if (vals.empty() || vals[0] == INT_MIN) return nullptr;

    TreeNode* root = new TreeNode(vals[0]);
    queue<TreeNode*> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < vals.size()) {
        TreeNode* current = q.front();
        q.pop();

        if (i < vals.size() && vals[i] != INT_MIN) {
            current->left = new TreeNode(vals[i]);
            q.push(current->left);
        }
        i++;

        if (i < vals.size() && vals[i] != INT_MIN) {
            current->right = new TreeNode(vals[i]);
            q.push(current->right);
        }
        i++;
    }

    return root;

};