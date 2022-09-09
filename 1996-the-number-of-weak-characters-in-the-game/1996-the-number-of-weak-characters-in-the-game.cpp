class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& props) {
        sort(props.begin(), props.end());
        int ans = 0, n = props.size();
        int i = n-1, maxDef = props[n-1][1], prevMaxDef = INT_MIN;
        while (i >= 0) {
            int j = i;
            while (j >= 0 and props[j][0] == props[i][0]) {
                if (props[j][1] < prevMaxDef) {
                    ans++;
                }
                maxDef = max(maxDef, props[j][1]);
                j--;
            }
            i = j;
            prevMaxDef = max(maxDef, prevMaxDef);
        }
        return ans;
    }
};