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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        queue<TreeNode*> adr;
        TreeNode * temp;
        adr.push(root);
        adr.push(nullptr);
        long long sum = 0, count = 0;
        while (adr.size()) {
            temp = adr.front();
            adr.pop();
            
            if (temp) {
                sum += temp->val;
                count++;
                if (temp->left)
                    adr.push(temp->left);
                if (temp->right)
                    adr.push(temp->right);
            } else {
                double avg = sum / (double)(count);
                ans.push_back(avg);
                sum = 0, count = 0;
                if (adr.size()) {
                    adr.push(nullptr);
                }
            }
        }
        return ans;
    }
};