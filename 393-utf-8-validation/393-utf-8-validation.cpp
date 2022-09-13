class Solution {
public:
    int countBits(int & n) {
        int count = 0, i = 7;
        while (i >= 4 and (n & (1 << i))) {
            i--;
            count++;
        }
        return count;
    }
    bool validUtf8(vector<int>& data) {
        int i = 0, n = data.size();
        while (i < data.size()) {
            int bits = countBits(data[i]);
            if (bits == 1) return false;
            else if (bits == 0) i++;
            else {
                if (i + bits > n) return false;
                if ((1 << (8-bits-1)) & data[i]) return false;
                i++;
                while (bits > 1) {
                    if (countBits(data[i]) != 1)
                        return false;
                    i++;
                    bits--;
                }
            }
        }
        for (int i = 0; i < data.size(); i++) {
            cout << countBits(data[i]) << " ";
        }
        return true;
    }
};