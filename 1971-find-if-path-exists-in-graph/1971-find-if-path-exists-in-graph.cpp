class Solution {
private:
    bool dfs(int node, int destination, vector<vector<int>>& adj, vector<int>& vis) {
        // Base Case: Agar hum chalte-chalte destination tak pahunch gaye!
        if (node == destination) return true;
        
        vis[node] = 1; // Current node ko visited mark kiya

        // Uske saare padosiyon par check karo
        for (auto neighbor : adj[node]) {
            if (!vis[neighbor]) {
                // Agar padosi ke raste se destination mil jata hai, toh aage check karne ki zaroorat nahi
                if (dfs(neighbor, destination, adj, vis) == true) {
                    return true;
                }
            }
        }
        
        return false; // Agar is node se koi raasta destination tak nahi jata
    }

public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        // Base Case: Agar source aur destination khud ek hi node hain
        if (source == destination) return true;

        // Step 1: Adjacency List build karo (Undirected graph hai, toh dono taraf edge judegi)
        vector<vector<int>> adj(n);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        // Step 2: Visited array bano loop se bachne ke liye
        vector<int> vis(n, 0);

        // Step 3: Source se DFS call karo
        return dfs(source, destination, adj, vis);
    }
};