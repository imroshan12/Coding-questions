class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {        
        sort(nums.begin(), nums.end());
        int n = nums.size(), closest = INT_MAX, ans = 0;
        for(int i = 0; i < n; i++)
        {
            if(i == 0 || (i > 0 && nums[i] != nums[i-1]))
            {
                int l = i+1, h = n-1, sum = target-nums[i];
                while(l < h)
                {
                    int x = nums[l] + nums[h];
                    if (abs(x - sum) < closest)
                    {
                        closest = abs(x-sum);
                        ans = x + nums[i];
                    }
                    x > sum?h--:l++;
                }
            }
        }
        return ans;
    }
};