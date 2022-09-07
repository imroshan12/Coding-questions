class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size(), ans = 1, p1 = 0, p2 = 0;
        vector<vector<int>> dp (n, vector<int> (n, 0));
        for (int i = 0; i < n; i++) {
            dp[i][i] = 1;
            if (i > 0 && s[i] == s[i - 1])
                dp[i][i-1] = 1, ans = 2, p1 = i-1, p2 = i;
        }
        for (int i = 2; i < n; i++) {
            for (int j = 0; j < i - 1; j++) {
                if (s[j] == s[i] && dp[i-1][j+1]){
                    dp[i][j] = 1;
                    int len = i - j + 1;
                    if (len > ans) {
                        ans = len;
                        p1 = j;
                        p2 = i;
                    }
                }
            }
        }
        return s.substr(p1, ans);
    }
};