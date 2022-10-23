class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> detect, aux(10001);
        int culp;
        for(int i = 0; i < nums.size(); i++)
        {
            aux[nums[i]] ^= nums[i];
            if(aux[nums[i]] == 0)
            {
                culp = nums[i];
                break;
            }
        }
        detect.push_back(culp);
        int actualSum = (nums.size()+1)*nums.size()/2;
        int expSum = accumulate(nums.begin(), nums.end(), 0);
        int error = actualSum - expSum;
        // cout << error << " " << culp << endl;
        detect.push_back(culp+error);
        return detect;
    }
};