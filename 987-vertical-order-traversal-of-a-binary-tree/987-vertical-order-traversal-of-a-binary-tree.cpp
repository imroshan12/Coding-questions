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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans, hash(2005);
        // vector<vector<pair<int, int>>> hash2(2005);
        queue<pair<TreeNode*, int>> adr;
        auto temp = root;
        int pos = 0, flag = -1;
        adr.push({root, 0});
        adr.push({nullptr, 0});
        unordered_map<int, vector<int>> tempHash;
        while (adr.size()) {
            temp = (adr.front()).first;
            pos = (adr.front()).second;
            adr.pop();
            if (temp) {
                tempHash[1002 + pos].push_back(temp->val);
                // hash[1002 + pos].push_back(temp->val);
                if (temp->left) {
                    adr.push({temp->left, pos - 1});
                }
                if (temp->right) {
                    adr.push({temp->right, pos + 1});
                }
            } else {
                for (auto &it: tempHash) {
                    sort((it.second).begin(), (it.second).end());
                    hash[it.first].insert(hash[it.first].end(), (it.second).begin(), (it.second).end());
                }
                if (adr.size()) {
                    tempHash.clear();
                    adr.push({nullptr, 0});
                }
            }

        }
        for (auto & vec: hash) {
            if (vec.size()) {
                ans.push_back(vec);
            }
        }
        return ans;
    }
};