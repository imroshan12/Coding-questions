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
        cout << num << " " << den << endl;
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
                cout << num << " ";
            } else {
                if (!point) {
                    // cout << "notP-- ";
                    if (ans.size()) {
                        ans += ".";
                    } else {
                        ans += "0.";
                    }
                    // x1 = num;
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
                    // hash[num] = 1;
                } else {
                    // cout << "p-- ";
                    if (hash.find(num) != hash.end()) {
                        // cout << "here " << num << endl;
                        // count++;
                        // if (pos1 == -1)
                        //     pos1 = ans.size();
                        // // else {
                        // //     pos2 = ans.size();
                        // //     break;
                        // // }
                        // cout << pos1 << " " << pos2 << endl;
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
                    // x1 = num;
                    // hash[num] = 1;
                }
            }
            // cout << ans << " ";
            // cout << pos1 << " " << pos2 << " " << count << endl;
        }
        // cout << pos1 << " " << len << endl;
        if (point and count) {
            // string rep = ans.substr(ans.size() - (pos2 - pos1), pos2 - pos1);
            // string noRep = ans.substr(0, ans.size() - 2*(pos2 - pos1));
            // string finalString = noRep + "(" + rep + ")";
            if (x) {
                pos1--;
                len++;
            }
            string rep = ans.substr(pos1, len);
            string noRep = ans.substr(0, pos1);
            string finalString = noRep + "(" + rep + ")";
            // cout << rep << " " << noRep << endl;
            if (neg)
                finalString = "-" + finalString;
            return finalString;
        }
        if (neg)
            ans = "-" + ans;
        return ans;
    }
};