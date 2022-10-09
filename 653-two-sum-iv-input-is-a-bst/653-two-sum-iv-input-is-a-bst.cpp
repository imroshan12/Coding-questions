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
    bool ans = false;
    unordered_map<int, int> hash;
public:
    void isPossible(TreeNode* root, int k) {
        if (!root) return;
        if (hash.find(k - (root->val)) != hash.end()) {
            ans = 1;
        } else {
            hash[root->val] = 1;
        }
        isPossible(root->left, k);
        isPossible(root->right, k);
    }
    bool findTarget(TreeNode* root, int k) {
        isPossible(root, k);
        return ans;
    }
};