class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        priority_queue<pair<int, int>> pq;
        vector<int> ans(k);
        for (int & e: arr) {
            pq.push({abs(e-x), e});
        }
        for (int i = 0; i < n-k; i++) {
            pq.pop();
        }
        int i = 0;
        while (pq.size()) {
            ans[i++] = pq.top().second;
            pq.pop();
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};