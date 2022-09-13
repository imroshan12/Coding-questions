class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size(), preProd = 1;
        vector<int> ans(n, 1);
        for (int i = n-2; i >= 0; i--) {
            ans[i] = nums[i+1]*ans[i+1];
        }
        for (int i = 0; i < n; i++) {
            ans[i] = preProd*ans[i];
            preProd *= nums[i];
        }
        return ans;
    }
};