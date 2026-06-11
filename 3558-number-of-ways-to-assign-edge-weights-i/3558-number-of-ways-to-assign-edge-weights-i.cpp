class Solution {
private:
    // DFS function to find the maximum depth (number of edges) from root 1
    void findMaxDepth(int node, int parent, int currentDepth, vector<vector<int>>& adj, int& maxDepth) {
        maxDepth = max(maxDepth, currentDepth);

        for (auto neighbor : adj[node]) {
            // Tree me backtrack hone se rokne ke liye parent check zaroori hai
            if (neighbor != parent) {
                findMaxDepth(neighbor, node, currentDepth + 1, adj, maxDepth);
            }
        }
    }

    // Binary Exponentiation to compute (base^exp) % mod in O(log exp) time
    long long power(long long base, long long exp, long long mod) {
        long long res = 1;
        base = base % mod;
        while (exp > 0) {
            if (exp % 2 == 1) {
                res = (res * base) % mod;
            }
            base = (base * base) % mod;
            exp /= 2;
        }
        return res;
    }

public:
    int assignEdgeWeights(vector<vector<int>>& edges) {
        // Tree me nodes ki sankhya (edges.size() + 1) hoti hai hamesha
        int n = edges.size() + 1;
        
        // 1-based indexing tree ke liye adjacency list
        vector<vector<int>> adj(n + 1);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        int maxDepth = 0;
        
        // Root 1 se DFS shuru kiya, shuruaat me parent = -1 aur depth = 0
        findMaxDepth(1, -1, 0, adj, maxDepth);

        // Agar tree me edges hi nahi hain (sirf 1 node hai), toh 0 ways
        if (maxDepth == 0) return 0;

        long long MOD = 1e9 + 7;

        // Formula: 2^(maxDepth - 1) % MOD
        return power(2, maxDepth - 1, MOD);
    }
};