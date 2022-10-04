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
    bool haspath (TreeNode * root, int & targetSum, int currSum) {
        if (!root) return 0;
        currSum += root->val;
        if (!root->left and !root->right) {
            if (currSum == targetSum)
                return true;
            return false;
        }
        bool left = haspath(root->left, targetSum, currSum);
        bool right = haspath(root->right, targetSum, currSum);
        return left or right;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return haspath(root, targetSum, 0);
    }
};