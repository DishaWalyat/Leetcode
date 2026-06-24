class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // Graph preparation: adj[u] = {v, price}
        vector<vector<pair<int, int>>> adj(n);
        for (auto& f : flights) {
            adj[f[0]].push_back({f[1], f[2]});
        }

        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        // Queue structure (Normal Queue works beautifully here because steps increase linearly by 1):
        // Format: {stops, {node, cost}}
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {src, 0}});

        while (!q.empty()) {
            int stops = q.front().first;
            int node = q.front().second.first;
            int cost = q.front().second.second;
            q.pop();

            // Agar stops limit cross ho gayi, toh aage explore mat karo
            if (stops > k) continue;

            for (auto& neighbor : adj[node]) {
                int nextNode = neighbor.first;
                int price = neighbor.second;

                // Relaxation condition based on budget constraint
                if (cost + price < dist[nextNode]) {
                    dist[nextNode] = cost + price;
                    q.push({stops + 1, {nextNode, dist[nextNode]}});
                }
            }
        }

        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};