class Solution {
public:
    string intToRoman(int num) {
        unordered_map<int, string> hash;
        hash[1] = "I", hash[5] = "V", hash[10] = "X", hash[50] = "L";
        hash[100] = "C", hash[500] = "D", hash[1000] = "M", hash[5000] = "B";
        int x = num, place = 1;
        string s = "";
        while (x > 0) {
            int lastDig = x % 10;
            string x1 = hash[place], x2 = hash[place*5], x3 = hash[place*10];
            switch (lastDig) {
                case 1:
                    s = x1 + s;
                    break;
                case 2:
                    s = x1 + x1 + s;
                    break;
                case 3:
                    s = x1 + x1 + x1 + s;
                    break;
                case 4:
                    s = x1 + x2 + s;
                    break;
                case 5:
                    s = x2 + s;
                    break;
                case 6:
                    s = x2 + x1 + s;
                    break;
                case 7:
                    s = x2 + x1 + x1 + s;
                    break;
                case 8:
                    s = x2 + x1 + x1 + x1 + s;
                    break;
                case 9:
                    s = x1 + x3 + s;
                    break;
                default:
                    s = s;
                    break;
            }
            place *= 10;
            x = x / 10;
        }
        return s;
    }
};