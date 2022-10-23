class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_map<int, int> hash;
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            hash[nums[i]]++;
            if (hash[nums[i]] > 1)
            ans.push_back(nums[i]);
        }
        for (int i = 1; i <= nums.size(); i++) {
            if (hash[i] == 0) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};