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
    int ans = 0;
    // need something like a running max
    void helper(TreeNode* root, int curMax) {
        if (!root) {
            return;
        }
        if (root->val >= curMax) {
            ans++;
            curMax = max(curMax, root->val);
        }
        helper(root->left, curMax);
        helper(root->right, curMax);
    }
    int goodNodes(TreeNode* root) {
        helper(root, root->val);
        return ans;
    }
};
