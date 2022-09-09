class Solution {
public:
    static bool comparator(vector<int> a, vector<int> b) {
        if (a[0] < b[0])
            return true;
        else if (a[0] == b[0])
            return a[1] < b[1];
        return false;
    }
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
            // if (i >= 0 and props[i][1] < prevMaxDef)
            //     ans++;
        }
        return ans;
    }
};