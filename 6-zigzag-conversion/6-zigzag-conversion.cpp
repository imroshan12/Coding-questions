class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1)
            return s;
        int n = s.size();
        int pos = 0;
        string ans = "";
        for (int i = 0; i < numRows; i++) {
            int first = 2*(numRows-1-i), second = 2*(i-0);
            int c = 0, pos = i;
            while (pos < n) {
                ans += s[pos];
                if (i == 0 || i == numRows - 1) {
                    pos += max(first, second);
                } else if (c & 1) {
                    pos += second;
                } else {
                    pos += first;
                }
                c++;
            }
        }
        return ans;
    }
};