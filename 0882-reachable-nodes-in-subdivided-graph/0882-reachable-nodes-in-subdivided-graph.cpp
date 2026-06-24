class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        // Graph formulation: adj[u] = {v, mini_nodes_count}
        vector<vector<pair<int, int>>> adj(n);
        for (auto& edge : edges) {
            adj[edge[0]].push_back({edge[1], edge[2]});
            adj[edge[1]].push_back({edge[0], edge[2]});
        }

        vector<int> dist(n, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        dist[0] = 0;
        pq.push({0, 0});

        // Step 1: Standard Dijkstra to find shortest path to original vertices
        while (!pq.empty()) {
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if (d > dist[node]) continue;

            for (auto& edge : adj[node]) {
                int neighbor = edge.first;
                int weight = edge.second + 1; // Mini nodes + 1 gives edge step weight

                if (d + weight < dist[neighbor]) {
                    dist[neighbor] = d + weight;
                    pq.push({dist[neighbor], neighbor});
                }
            }
        }

        int reachableCount = 0;
        // Step 2: Count reachable original nodes
        for (int i = 0; i < n; i++) {
            if (dist[i] <= maxMoves) {
                reachableCount++;
            }
        }

        // Step 3: Count reachable subdivision mini-nodes along the edges
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int cnt = edge[2];

            // Node u se is edge ke kitne chote nodes explore ho paaye
            int reachFromU = (dist[u] <= maxMoves) ? (maxMoves - dist[u]) : 0;
            // Node v se is edge ke kitne chote nodes explore ho paaye
            int reachFromV = (dist[v] <= maxMoves) ? (maxMoves - dist[v]) : 0;

            // Total chote nodes jo is individual edge par cover huye
            // Max capacity total total mini-nodes (cnt) se badi nahi ho sakti
            reachableCount += min(cnt, reachFromU + reachFromV);
        }

        return reachableCount;
    }
};