class Solution {
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        for (const auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        vector<int> count(n, 1); // Tracks size of subtree for each node
        vector<int> ans(n, 0);   // Stores the final answer for each node
        
        // Pass 1: Compute subtree sizes and answer for the root (node 0)
        dfs1(0, -1, graph, count, ans);
        
        // Pass 2: Re-root and compute answers for all other nodes
        dfs2(0, -1, n, graph, count, ans);
        
        return ans;
    }

private:
    void dfs1(int node, int parent, const vector<vector<int>>& graph, 
              vector<int>& count, vector<int>& ans) {
        for (int neighbor : graph[node]) {
            if (neighbor != parent) {
                dfs1(neighbor, node, graph, count, ans);
                // After returning, the child's subtree size is fully computed
                count[node] += count[neighbor];
                // Accumulate distances to root: child's distances + 1 step for every node in child's subtree
                ans[node] += ans[neighbor] + count[neighbor];
            }
        }
    }

    void dfs2(int node, int parent, int n, const vector<vector<int>>& graph, 
              const vector<int>& count, vector<int>& ans) {
        for (int neighbor : graph[node]) {
            if (neighbor != parent) {
                // Apply the rerooting transition formula
                ans[neighbor] = ans[node] - count[neighbor] + (n - count[neighbor]);
                // Continue down to its children
                dfs2(neighbor, node, n, graph, count, ans);
            }
        }
    }
};