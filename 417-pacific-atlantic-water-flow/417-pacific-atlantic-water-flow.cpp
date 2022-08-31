typedef vector<vector<int>> vi;
class Solution {
    unordered_map<string, bool> pac;
    unordered_map<string, bool> atl;
    vi ans;
public:
    void dfs(int r, int c, unordered_map<string, bool> &vis, int prev, vi & heights) {
        string key = to_string(r) + "," + to_string(c);
        if (vis.find(key) != vis.end() or r < 0 or c < 0 or r == heights.size() or c == heights[0].size() or heights[r][c] < prev)
            return;
        vis[key] = 1;
        dfs(r + 1, c, vis, heights[r][c], heights);
        dfs(r - 1, c, vis, heights[r][c], heights);
        dfs(r, c + 1, vis, heights[r][c], heights);
        dfs(r, c - 1, vis, heights[r][c], heights);
        if (atl.find(key) != atl.end() and pac.find(key) != pac.end())
            ans.push_back({r, c});
    }
    vector<vector<int>> pacificAtlantic(vi & heights) {
        int m = heights.size(), n = heights[0].size();
        for (int j = 0; j < n; j++) {
            dfs(0, j, pac, heights[0][j], heights);
            dfs(m-1, j, atl, heights[m-1][j], heights);
        }
        for (int i = 0; i < m; i++) {
            dfs(i, 0, pac, heights[i][0], heights);
            dfs(i, n-1, atl, heights[i][n-1], heights);
        }
        return ans;
    }
};