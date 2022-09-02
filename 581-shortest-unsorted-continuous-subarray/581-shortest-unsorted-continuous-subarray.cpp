class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> newArr(n);
        for (int i = 0; i < n; i++) {
            newArr[i].first = nums[i];
            newArr[i].second = i;
        }
        sort(newArr.begin(), newArr.end());
        vector<int> pos(2, -1);
        for (int i = 0; i < n; i++) {
            if (newArr[i].second != i) {
                if (pos[0] == -1) pos[0] = i;
                else pos[1] = i;
            }
        }
        if (pos[0] != -1) {
            if (pos[1] == -1)
                return n-pos[0];
            else
                return pos[1]-pos[0]+1;
        }
        return 0;
    }
};