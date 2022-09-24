class Solution {
public:    
    int dfs(TreeNode* root, long long int curr, long long int targetSum){
        if(!root) return 0;
        return (curr+root->val == targetSum) + dfs(root->left, curr+root->val, targetSum) + dfs(root->right, curr+root->val, targetSum);
    };
    
    int pathSum(TreeNode* root, int targetSum) {
        if(!root) return 0;
        return dfs(root, 0 , targetSum) + pathSum(root->left, targetSum) + pathSum(root->right, targetSum);
    }
};