class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);
        stack<int> st;
        for (int i = 2*n - 1; i >= 0; i--) {
            int j = i >= n ? i % n : i;
            while (st.size() && st.top() <= nums[j]) {
                st.pop();
            }
            if (i < n && st.size())
                ans[i] = st.top();
            st.push(nums[j]);
        }
        return ans;
    }
};