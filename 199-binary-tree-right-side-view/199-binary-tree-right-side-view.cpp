class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if (!root) return ans;
        
        queue<TreeNode*> adr;
        TreeNode* temp;
        
        adr.push(root);
        adr.push(nullptr);
        
        while (adr.size()) {
            temp = adr.front();
            adr.pop();
            if (temp) {
                if (adr.front() == nullptr) 
                    ans.push_back(temp->val);
                
                if (temp->left)
                    adr.push(temp->left);
                
                if (temp->right)
                    adr.push(temp->right);
                
            } else {
                if (adr.size()) 
                    adr.push(nullptr);
            }
        }
        return ans;
    }
};