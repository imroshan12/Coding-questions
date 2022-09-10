class Solution {
public:
    string fractionToDecimal(int num1, int den) {
        string ans = "";
        bool point = false, neg = false;
        if (num1 == 0)
            return "0";
        if ((num1 < 0 and den > 0) or (num1 > 0 and den < 0)) {
            neg = true;
        }
        long long num = num1;
        int x1 = num, count = 0;
        int pos1 = -1, pos2 = -1;
        int len = 0;
        bool x = false;
        unordered_map<int, int> hash;
        num = abs(num);
        den = abs(den);
        if (den == 1) {
            ans = to_string(num);
            if (neg)
                ans = "-" + ans;
            return ans;
        }
        while (num > 0) {
            int factor = num / den;
            int rem = num % den;
            if (factor > 0 and (!point)) {
                hash[num] = 1;
                ans += to_string(factor);
                num = rem;
            } else {
                if (!point) {
                    if (ans.size()) {
                        ans += ".";
                    } else {
                        ans += "0.";
                    }
                    hash[num] = ans.size();
                    num = num*10;
                    while (num < den) {
                        num = num*10;
                        ans += "0";
                    }
                    factor = num / den;
                    rem = num % den;
                    ans += to_string(factor);
                    num = rem;
                    point = true;
                } else {
                    if (hash.find(num) != hash.end()) {
                        count++;
                        pos1 = hash[num];
                        if (ans[pos1-1] == '.') {
                            pos1++;
                            len = ans.size() - pos1 + 1; 
                            x = true;
                        } else {
                            len = ans.size() - pos1;   
                        }
                        break;
                    }
                    hash[num] = ans.size();   
                    num = num*10;
                    while (num < den) {
                        num = num*10;
                        ans += "0";
                    }
                    factor = num / den;
                    rem = num % den;
                    ans += to_string(factor);
                    num = rem;
                }
            }
        }
        if (point and count) {
            if (x) {
                pos1--;
                len++;
            }
            string rep = ans.substr(pos1, len);
            string noRep = ans.substr(0, pos1);
            string finalString = noRep + "(" + rep + ")";
            if (neg)
                finalString = "-" + finalString;
            return finalString;
        }
        if (neg)
            ans = "-" + ans;
        return ans;
    }
};