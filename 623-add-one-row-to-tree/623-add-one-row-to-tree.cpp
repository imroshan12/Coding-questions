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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) {
            TreeNode * newRoot = new TreeNode(val, root, nullptr);
            return newRoot;
        }
        queue<TreeNode*> adr;
        adr.push(root);
        adr.push(nullptr);
        TreeNode * temp;
        int level = 1;
        while (adr.size()) {
            temp = adr.front();
            adr.pop();
            if (temp) {
                TreeNode *newLeft= new TreeNode(val), *newRight= new TreeNode(val);
                if (level == depth - 1) {
                    // if (temp->left) {
                        newLeft->left = temp->left;
                        temp->left = newLeft;
                    // }
                    // if (temp->right) {
                        newRight->right = temp->right;
                        temp->right = newRight;
                    // }
                // } else if (level == depth) {
                //     int x = 0;
                } else {
                    if (temp->left)
                        adr.push(temp->left);
                    if (temp->right)
                        adr.push(temp->right);
                }
            } else {
                level++;
                if (level == depth)
                    break;
                if (adr.size()) 
                    adr.push(nullptr);
            }
        }
        return root;
    }
};