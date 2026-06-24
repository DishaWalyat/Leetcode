class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // direct dijstra ka question hai :)
        vector<vector<pair<int, int>>> adj(n + 1);
        for (auto& edge : times) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            adj[u].push_back({v, w});
        }
        vector<int> dist(n + 1, INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int, int>>> pq;
        dist[k] = 0;
        pq.push({0, k});

        while (!pq.empty()) {
            int currentTime = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            // Optimization Check: Purane bade paths ko ignore karo
            if (currentTime > dist[node]) continue;

            // Padosiyon par travel karo
            for (auto& edge : adj[node]) {
                int neighbor = edge.first;
                int weight = edge.second;

                // Edge Relaxation
                if (currentTime + weight < dist[neighbor]) {
                    dist[neighbor] = currentTime + weight;
                    pq.push({dist[neighbor], neighbor});
                }
            }
        }

        // Step 4: Max Time extraction aur validity checking
        int maxTime = 0;
        for (int i = 1; i <= n; i++) {
            // Agar ek bhi node unvisited reh gaya, toh network incomplete hai
            if (dist[i] == INT_MAX) {
                return -1;
            }
            maxTime = max(maxTime, dist[i]);
        }

        return maxTime;
    }
};
