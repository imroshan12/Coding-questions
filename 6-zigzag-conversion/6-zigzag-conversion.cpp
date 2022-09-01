class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1)
            return s;
        int n = s.size(), c = 0;
        vector<vector<char>> zig(1000, vector<char> (1000));
        int i = 0, j = 0;
        string ans = "";
        while (c < n) {
            for (i = 0; i < (numRows - 1) && c < n; i++) {
                // cout << i << " " << j << endl;
                zig[i][j] = s[c++];
            }
            for (i = (numRows - 1); i > 0 && c < n; i--, j++) {
                // cout << i << " " << j << endl;
                zig[i][j] = s[c++];
            }
            // cout << i << " " << j << endl;
        }
        // cout << c << endl;
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < 1000; j++) {
                // cout << zig[i][j] << " ";
                if (zig[i][j])
                    ans += zig[i][j];
            }
            
            // cout << endl;
        }
        return ans;
    }
};