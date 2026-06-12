class Solution {
private:
    int logN;
    vector<int> depth;
    vector<vector<int>> up; // Binary lifting table

    // DFS to precompute depths and the first ancestor (2^0)
    void dfs(int node, int parent, int d, vector<vector<int>>& adj) {
        depth[node] = d;
        up[node][0] = parent;
        
        // Binary lifting table bharna
        for (int j = 1; j < logN; j++) {
            if (up[node][j - 1] != -1) {
                up[node][j] = up[up[node][j - 1]][j - 1];
            } else {
                up[node][j] = -1;
            }
        }

        for (auto neighbor : adj[node]) {
            if (neighbor != parent) {
                dfs(neighbor, node, d + 1, adj);
            }
        }
    }

    // Function to find Lowest Common Ancestor in O(log N)
    int getLCA(int u, int v) {
        if (depth[u] < depth[v]) swap(u, v);

        // Diff nikal kar dono ko same level par laana
        int diff = depth[u] - depth[v];
        for (int j = 0; j < logN; j++) {
            if ((diff >> j) & 1) {
                u = up[u][j];
            }
        }

        if (u == v) return u;

        // Dono ko sath me upar lift karna jab tak LCA ke just neeche na pahunchen
        for (int j = logN - 1; j >= 0; j--) {
            if (up[u][j] != up[v][j]) {
                u = up[u][j];
                v = up[v][j];
            }
        }
        return up[u][0];
    }

    // Binary Exponentiation
    long long power(long long base, long long exp, long long mod) {
        if (exp < 0) return 0;
        long long res = 1;
        base = base % mod;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % mod;
            base = (base * base) % mod;
            exp /= 2;
        }
        return res;
    }

public:
    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        int n = edges.size() + 1;
        logN = ceil(log2(n)) + 1;

        vector<vector<int>> adj(n + 1);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        depth.assign(n + 1, 0);
        up.assign(n + 1, vector<int>(logN, -1));

        // Root 1 se precomputation shuru (parent of root is -1)
        dfs(1, -1, 0, adj);

        long long MOD = 1e9 + 7;
        vector<int> ans;

        for (auto& query : queries) {
            int u = query[0];
            int v = query[1];

            int lca = getLCA(u, v);
            // Total edges on the path between u and v
            int k = depth[u] + depth[v] - 2 * depth[lca];

            if (k == 0) {
                ans.push_back(0); // Same node ke beech koi edge nahi
            } else {
                ans.push_back(power(2, k - 1, MOD));
            }
        }

        return ans;
    }
};