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
    string tree2str(TreeNode* root) {
        if (!root)
            return "";
        string left = tree2str(root->left);
        string right = tree2str(root->right);
        
        string finalString = "";
        if (!left.size() and !right.size())
            finalString = to_string(root->val);
        else {
            finalString = to_string(root->val) + "(" + left + ")";
            if (right != "")
                finalString += "(" + right + ")";
        }
            
        return finalString;
    }
};