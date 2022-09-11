class Solution {
public:
    static bool comparator (pair<int, int> a, pair<int, int> b) {
        return a.first > b.first;
    }
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int, int>> combined;
        for (int i = 0; i < n; i++) {
            combined.push_back({efficiency[i], speed[i]});
        }
        sort(combined.begin(), combined.end(), comparator);
        long long currSpeed = 0, ans = 0;
        int mod = 1e9 + 7;
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < n; i++) {
            if (pq.size() == k) {
                currSpeed -= pq.top();
                pq.pop();
            }
            currSpeed += combined[i].second;
            pq.push(combined[i].second);
            ans = max(ans, currSpeed*combined[i].first);
        }
        return ans % mod;
    }
};