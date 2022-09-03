class Solution {
public:
    void getNumbers(int num, int & k, int pos, vector<int> & ans) {
        if (pos <= 0) {
            ans.push_back(num);
            return;
        }
        int prec = num % 10;
        int next1 = prec - k, next2 = prec + k;
        if (k == 0) {
            getNumbers(num*10 + prec, k, pos - 1, ans);
            return;
        }
        if (next1 >= 0 && next1 <= 9) {
            getNumbers(num*10 + next1, k, pos - 1, ans);
        }
        if (next2 >= 0 && next2 <= 9) {
            getNumbers(num*10 + next2, k, pos - 1, ans);
        }
        
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> ans;
        for (int i = 1; i <= 9; i++) {
            getNumbers(i, k, n-1, ans);
        }
        return ans;
    }
};