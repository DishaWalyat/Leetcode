class Solution {
private:
    bool dfsCheck(int node, vector<int> adj[], vector<int>& vis, vector<int>& pathVis) {
        vis[node] = 1;
        pathVis[node] = 1; // Current path me mark kiya
        
        for(auto it : adj[node]) {
            // Case 1: Agar node visited nahi hai, toh aage DFS check karo
            if(!vis[it]) {
                if(dfsCheck(it, adj, vis, pathVis) == true) return true;
            }
            // Case 2: Agar node isi SAME PATH me pehle se visited hai -> Cycle Found!
            else if(pathVis[it]) {
                return true;
            }
        }
        
        pathVis[node] = 0; // Backtrack: Path se hatao jab function return karega
        return false;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int V = numCourses;
        vector<int> adj[V];
        
        // Sahi tarika adjacency list banane ka (Directed Graph)
        for(auto it : prerequisites) {
            adj[it[1]].push_back(it[0]); // Course it[1] karne ke baad hi it[0] kar sakte hain
        }

        vector<int> vis(V, 0);
        vector<int> pathVis(V, 0); // Extra array directed graph ke liye

        for(int i = 0; i < V; i++) {
            if(!vis[i]) {
                if(dfsCheck(i, adj, vis, pathVis) == true) {
                    // Agar cycle mili, toh courses complete NAHI ho sakte
                    return false; 
                }
            }
        }
        
        // Agar koi cycle nahi mili, toh badhiya hai, can finish!
        return true; 
    }
};