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
private:
    int count = 0;
public:
    void countPaths (TreeNode * root, int & targetSum, int currSum) {
        if (!root) return;
        currSum += root->val;
        if (!root->left and !root->right and currSum == targetSum) {
            count++;
            return;
        }
        countPaths(root->left, targetSum, currSum);
        countPaths(root->right, targetSum, currSum);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        countPaths(root, targetSum, 0);
        return count;
    }
};