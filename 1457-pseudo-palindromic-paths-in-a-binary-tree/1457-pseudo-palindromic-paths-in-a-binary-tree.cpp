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
    int count = 0;
    void countPaths(TreeNode* root, int num) {
        if (!root) {
            return;
        }
        num = num ^ (1 << (root->val - 1));
        if (!root->left and !root->right) {
            int maxOdd = 0;
            for (int i = 0; i < 9; i++) {
                if ((1 << i) & num)
                    maxOdd++;
            }
            if (maxOdd <= 1)
                count++;
        }
        countPaths(root->left, num);
        countPaths(root->right, num);
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        int num = 0;
        countPaths(root, num);
        return count;
    }
};