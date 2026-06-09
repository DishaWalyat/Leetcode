class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int V = numCourses;
        vector<int> adj[V];
        vector<int> indegree(V, 0);

        // Step 1: Adjacency List banana aur Indegree count karna
        for (auto it : prerequisites) {
            // it[1] -> it[0] (it[1] pehle karna hai, fir it[0] kar sakte hain)
            adj[it[1]].push_back(it[0]);
            indegree[it[0]]++;
        }

        // Step 2: Jinki indegree 0 hai, unhe queue me daalo
        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> topoOrder;

        // Step 3: Standard BFS standard loop
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topoOrder.push_back(node); // Node ko answer me daal diya

            // Uske saare padosiyon ki dependency kam karo
            for (auto neighbor : adj[node]) {
                indegree[neighbor]--;
                
                // Agar dependency 0 ho gayi, toh queue me push karo
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        // Step 4: Agar saare courses cover ho gaye, toh order return karo, varna {}
        if (topoOrder.size() == V) {
            return topoOrder;
        }
        return {}; // Cycle detected, order is impossible
    }
};