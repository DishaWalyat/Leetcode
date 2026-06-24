class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        long long MOD = 1e9 + 7;
        vector<vector<pair<int, int>>> adj(n);
        for (auto& r : roads) {
            adj[r[0]].push_back({r[1], r[2]});
            adj[r[1]].push_back({r[0], r[2]}); // Undirected graph
        }

        // Use long long to avoid integer overflow
        vector<long long> dist(n, LLONG_MAX);
        vector<long long> ways(n, 0);

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

        dist[0] = 0;
        ways[0] = 1; // Base case: Source tak pahunchne ka 1 raasta hai
        pq.push({0, 0});

        while (!pq.empty()) {
            long long d = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if (d > dist[node]) continue;

            for (auto& edge : adj[node]) {
                int neighbor = edge.first;
                long long weight = edge.second;

                // Case 1: Strict Shortest Path Found
                if (d + weight < dist[neighbor]) {
                    dist[neighbor] = d + weight;
                    ways[neighbor] = ways[node]; // Carry over paths
                    pq.push({dist[neighbor], neighbor});
                }
                // Case 2: Another Alternate Path with Same Shortest Distance Found
                else if (d + weight == dist[neighbor]) {
                    ways[neighbor] = (ways[neighbor] + ways[node]) % MOD;
                }
            }
        }

        return ways[n - 1];
    }
};