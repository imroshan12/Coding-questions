class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return {};
        vector<int> ans;
        // Declare a queue
        queue<TreeNode*> adr;
        adr.push(root);
        adr.push(nullptr);
        // Declare a temporary variable for accessing a pointer
        TreeNode * temp;
        // Traversing in queue until it is not empty
        while (!adr.empty()) {
            temp = adr.front();
            adr.pop();
            // If the node is not a nullptr, then perform operation
            if (temp != nullptr) {
                if (adr.front() == nullptr) 
                    ans.push_back(temp->val);
                
                if (temp->left) 
                    adr.push(temp->left);
                if (temp->right) 
                    adr.push(temp->right);
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