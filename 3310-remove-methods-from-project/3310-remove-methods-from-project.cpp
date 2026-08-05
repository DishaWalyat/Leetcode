class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {

        // Build graph
        vector<vector<int>> adj(n);
        for (auto &e : invocations) {
            adj[e[0]].push_back(e[1]);
        }

        // Mark suspicious methods using BFS
        vector<bool> vis(n, false);
        queue<int> q;

        q.push(k);
        vis[k] = true;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int neigh : adj[node]) {
                if (!vis[neigh]) {
                    vis[neigh] = true;
                    q.push(neigh);
                }
            }
        }

        // Check if any non-suspicious method calls a suspicious one
        for (auto &e : invocations) {
            int u = e[0];
            int v = e[1];

            if (!vis[u] && vis[v]) {
                vector<int> ans;
                for (int i = 0; i < n; i++)
                    ans.push_back(i);
                return ans;
            }
        }

        // Return all non-suspicious methods
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (!vis[i])
                ans.push_back(i);
        }

        return ans;
    }
};