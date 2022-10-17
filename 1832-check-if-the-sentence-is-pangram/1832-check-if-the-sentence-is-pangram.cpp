class Solution {
public:
    bool checkIfPangram(string sentence) {
        int chars = 0, match = (1 << 26);
        for (int i = 0; i < sentence.size(); i++) {
            chars = chars | (1 << (sentence[i] - 'a'));
        }
        if (chars == match - 1) return true;
        return false;
    }
};