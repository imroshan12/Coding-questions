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
    long long getFactor(int len, long long prevFactor) {
        for (int i = 1; i <= len; i++) {
            prevFactor = (prevFactor * 2) % MOD;
        }
        return prevFactor;
    }
    int concatenatedBinary(int n) {
        int binaryLen = 0;
        long long prevFactor = 1, ans = 0;
        for (long long i = n; i >= 1; i--) {
            prevFactor = getFactor(binaryLen, prevFactor); 
            ans = (ans + i*prevFactor) % MOD;
            binaryLen = findLen(i);
        }
        return (int)ans;
    }
};