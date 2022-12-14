class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n = tokens.size();
        sort(tokens.begin(), tokens.end());
        int score = 0, maxScore = 0, i = 0, j = n-1;
        while (i <= j) {
            if (power >= tokens[i]) {
                power -= tokens[i++];
                score++;
                maxScore = max(maxScore, score);
            } else if (score > 0) {
                score--;
                power += tokens[j--];
            } else {
                break;
            }
        }
        return maxScore;
    }
};