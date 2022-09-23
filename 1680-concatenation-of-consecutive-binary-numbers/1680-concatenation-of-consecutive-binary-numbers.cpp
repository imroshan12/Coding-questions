class Solution {
private:
    long long MOD = 1e9+7;
public:
    int findLen(int n) {
        int len = 0;
        while (n) {
            len++;
            n = n >> 1;
        }
        return len;
    }
    long long getFactor(long long len, long long prevFactor) {
        // long long n = 1;
        // for (long long i = prevLen; i <= len; i++) {
        //     n = (n * 2) % MOD;
        // }
        // return n;
        for (long long i = 1; i <= len; i++) {
            prevFactor = (prevFactor * 2) % MOD;
        }
        return prevFactor;
    }
    int concatenatedBinary(int n) {
        string s = "";
        long long pos = 0, prevFactor = 1, ans = 0;
        for (long long i = n; i >= 1; i--) {
            // cout << getFactor(pos, prevFactor) << " ";
            prevFactor = getFactor(pos, prevFactor); 
            ans = (ans + i*prevFactor) % MOD;
            // prevPos = pos;
            pos = findLen(i);
        }
        return (int)ans;
    }
};