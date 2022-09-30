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
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return {};
        vector<int> ans;
        
        queue<TreeNode*> adr;
        adr.push(root);
        adr.push(nullptr);
        
        TreeNode * temp;
        
        while (!adr.empty()) {
            temp = adr.front();
            adr.pop();
            
            if (temp != nullptr) {
                if (adr.front() == nullptr) ans.push_back(temp->val);
                if (temp->left) adr.push(temp->left);
                if (temp->right) adr.push(temp->right);
            } else {
                if (!adr.empty())
                    adr.push(nullptr);
            }
        }
        return ans;
    }
};
























































// class Solution {
// public:
//     vector<int> rightSideView(TreeNode* root) {
//         vector<int> ans;
//         if (!root) return ans;
        
//         queue<TreeNode*> adr;
//         TreeNode* temp;
        
//         adr.push(root);
//         adr.push(nullptr);
        
//         while (adr.size()) {
//             temp = adr.front();
//             adr.pop();
//             if (temp) {
//                 if (adr.front() == nullptr) 
//                     ans.push_back(temp->val);
                
//                 if (temp->left)
//                     adr.push(temp->left);
                
//                 if (temp->right)
//                     adr.push(temp->right);
                
//             } else {
//                 if (adr.size()) 
//                     adr.push(nullptr);
//             }
//         }
//         return ans;
//     }
// };