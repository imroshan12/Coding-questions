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
    bool removeNodes(TreeNode **root) {
        if (!(*root))
            return 0;
        bool left = removeNodes(&(*root)->left);
        bool right = removeNodes(&(*root)->right);
        if (!left)
            (*root)->left = nullptr;
        if (!right)
            (*root)->right = nullptr;
        return left || right || (*root)->val;
    }
    TreeNode* pruneTree(TreeNode* root) {
        bool x = removeNodes(&root);
        if (x == 0)
            root = nullptr;
        return root;
    }
};