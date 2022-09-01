class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>> adj(n+1);
        for (int i = 1; i <= paths.size(); i++) {
            int x = paths[i-1][0], y = paths[i-1][1];
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        vector<int> ans(n), vis(n+1);
        for (int i = 1; i <= n; i++) {
            if (!vis[i]) {
                queue<int> q;
                q.push(i);
                vis[i] = 1;
                ans[i-1] = 1;
                
                while (q.size()) {
                    int node = q.front();
                    q.pop();
                    
                    vector<int> opt(5, 1);
                    for (auto it: adj[node]) {
                        if (vis[it]) {
                            opt[ans[it-1]] = 0;
                        }
                    }
                    for (int j = 1; j <= 4; j++) {
                        if (opt[j]) {
                            ans[node - 1] = j;
                            break;
                        }
                    }
                    for (auto it: adj[node]) {
                        if (!vis[it]) {
                            vis[it] = 1;
                            q.push(it);
                        }
                    } 
                }
            }
        }
        return ans;
    }
};