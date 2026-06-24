class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // Cost tracker initialized to Infinity
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        
        // Min-Priority Queue: {current_cost, {row, col}}
        priority_queue<pair<int, pair<int, int>>, 
                       vector<pair<int, pair<int, int>>>, 
                       greater<pair<int, pair<int, int>>>> pq;

        dist[0][0] = 0;
        pq.push({0, {0, 0}});

        // Directions mapped as per problem grid values: 1: Right, 2: Left, 3: Down, 4: Up
        int dx[] = {0, 0, 0, 1, -1};
        int dy[] = {0, 1, -1, 0, 0};

        while (!pq.empty()) {
            int cost = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            pq.pop();

            if (r == m - 1 && c == n - 1) return cost;
            if (cost > dist[r][c]) continue;

            // Check all 4 possible neighbor movements
            for (int dir = 1; dir <= 4; dir++) {
                int nr = r + dx[dir];
                int nc = c + dy[dir];

                if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                    // Agar grid ka active arrow aur hamari movement direction same hai -> cost = 0
                    // Varna direction badalne ki cost = 1
                    int edgeWeight = (grid[r][c] == dir) ? 0 : 1;

                    if (cost + edgeWeight < dist[nr][nc]) {
                        dist[nr][nc] = cost + edgeWeight;
                        pq.push({dist[nr][nc], {nr, nc}});
                    }
                }
            }
        }
        return 0;
    }
};