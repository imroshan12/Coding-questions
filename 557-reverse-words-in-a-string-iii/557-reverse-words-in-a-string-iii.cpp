class Solution {
public:
    void reverse(string & s, int i, int j) {
        while (i < j) {
            swap(s[i++], s[j--]);
        }
    }
    string reverseWords(string s) {
        int i = 0, n = s.size();
        while (i < n) {
            int j = i;
            while (j < n && s[j] != ' ') {
                j++;
            }
            reverse(s, i, j-1);
            j++;
            i = j;
        }
        return s;
    }
};