class Solution {
private:
    bool dfsCheck(int node, vector<vector<int>>& graph, vector<int>& vis, vector<int>& pathVis, vector<int>& check) {
        vis[node] = 1;
        pathVis[node] = 1;
        check[node] = 0; // Shuruat me maan lo safe nahi hai

        for (auto neighbor : graph[node]) {
            // Case 1: Agar padosi visited nahi hai, toh aage check karo
            if (!vis[neighbor]) {
                if (dfsCheck(neighbor, graph, vis, pathVis, check) == true) {
                    return true; // Cycle mili toh unsafe hai
                }
            }
            // Case 2: Agar padosi SAME PATH me pehle se visited hai -> Cycle Found!
            else if (pathVis[neighbor]) {
                return true; 
            }
        }

        // Agar loop bina cycle ke khatam hua, matlab yeh node ekdum SAFE hai!
        check[node] = 1; 
        pathVis[node] = 0; // Backtrack
        return false;
    }

public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> vis(V, 0);
        vector<int> pathVis(V, 0);
        vector<int> check(V, 0); // Safe nodes ko track karega
        
        vector<int> safeNodes;

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfsCheck(i, graph, vis, pathVis, check);
            }
        }

        // Jo jo nodes check array me 1 marked hain, unhe sorted order me daal do
        for (int i = 0; i < V; i++) {
            if (check[i] == 1) {
                safeNodes.push_back(i);
            }
        }

        return safeNodes;
    }
};