class Solution {
public:

    bool bfsCheck(int start, vector<vector<int>>& adj, vector<int>& color) {
        queue<int> q;
        q.push(start);
        color[start] = 0; // Shuruat wale node ko color 0 (Red) diya

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            for(auto neighbor : adj[node]) {
                // Case 1: Agar padosi ko abhi tak koi color nahi mila hai
                if(color[neighbor] == -1) {
                    color[neighbor] = 1 - color[node]; // Ulta color diya (0 ka 1, 1 ka 0)
                    q.push(neighbor);
                }
                // Case 2: Agar padosi pehle se colored hai aur uska color hamare jaisa hi hai
                else if(color[neighbor] == color[node]) {
                    return false; // Same color padosi mil gaye -> Not Bipartite!
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int V= graph.size();
        vector<int>color(V,-1);
        
        for(int i = 0; i < V; i++) {
            if(color[i] == -1) {
                if(bfsCheck(i, graph, color) == false) {
                    return false;
                }
            }
        }
        return true;
        
    }
};