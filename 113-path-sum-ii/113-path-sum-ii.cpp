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
    vector<vector<int>> paths;
public:
    void traverse(TreeNode * root, int sum, vector<int> path, int & targetSum) {
        if (!root) return;
        sum += root->val;
        path.push_back(root->val);
        if (!root->left && !root->right and sum == targetSum) {
            paths.push_back(path);
        }
        traverse(root->left, sum, path, targetSum);
        traverse(root->right, sum, path, targetSum);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> temp;
        traverse(root, 0, temp, targetSum);
        return paths;
    }
};