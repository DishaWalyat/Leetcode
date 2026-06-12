class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        
        // Min-Heap store karega: {current_effort, {row, col}}
        // Taaki hamesha sabse kam effort wala path sabse pehle pop ho
        priority_queue<pair<int, pair<int, int>>, 
                       vector<pair<int, pair<int, int>>>, 
                       greater<pair<int, pair<int, int>>>> pq;
        
        // Effort matrix ko infinity (1e9) se initialize kiya
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        
        // Starting point (0, 0) ka effort hamesha 0 hoga
        dist[0][0] = 0;
        pq.push({0, {0, 0}});
        
        // Directions arrays for 4-directional movement (Up, Right, Down, Left)
        int dr[] = {-1, 0, +1, 0};
        int dc[] = {0, +1, 0, -1};
        
        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            
            int diff = it.first;
            int r = it.second.first;
            int c = it.second.second;
            
            // Optimization Check: Agar hum purane bade effort wale element ko pop kar rahe hain
            if (diff > dist[r][c]) continue;
            
            // Base Case: Jaise hi hum bottom-right corner pahunche, wahi hamara optimal min-max effort hai
            if (r == n - 1 && c == m - 1) return diff;
            
            // 4 padosiyon par check karo
            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                
                // Boundary condition checks
                if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
                    // Naye path ka effort = (pichla effort) aur (current jump height) ka MAXIMUM
                    int newEffort = max(diff, abs(heights[r][c] - heights[nr][nc]));
                    
                    // Agar naya effort purane effort se chota mil gaya (Relaxation)
                    if (newEffort < dist[nr][nc]) {
                        dist[nr][nc] = newEffort;
                        pq.push({newEffort, {nr, nc}});
                    }
                }
            }
        }
        
        return 0; // Default fallback
    }
};