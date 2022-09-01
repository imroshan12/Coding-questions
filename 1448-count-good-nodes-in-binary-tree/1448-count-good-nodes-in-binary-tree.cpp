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
    int count = 0;
public:
    void countDfs(TreeNode * root, int par) {
        if (!root)
            return;
        if (root->val >= par)
            count++;
        par = max(par, root->val);
        countDfs(root->left, par);
        countDfs(root->right, par);
    }
    int goodNodes(TreeNode* root) {
        countDfs(root, INT_MIN);
        return count;
    }
};