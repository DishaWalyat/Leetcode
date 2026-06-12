class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        
        // Base Case 1: Agar source ya destination hi blocked (1) ho
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;
        
        // Base Case 2: Agar single cell matrix hai [[0]]
        if (n == 1 && grid[0][0] == 0) return 1;

        // Distance matrix ko infinity se initialize kiya
        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        queue<pair<int, int>> q;

        // Path ki length number of cells hoti hai, isliye starting distance = 1
        dist[0][0] = 1;
        q.push({0, 0});

        // 8 Directions ke offsets (All neighbors including diagonals)
        int delRow[] = {-1, -1, -1, 0, 0, +1, +1, +1};
        int delCol[] = {-1, 0, +1, -1, +1, -1, 0, +1};

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            // 8 padosiyon ko scan karo
            for (int i = 0; i < 8; i++) {
                int nrow = r + delRow[i];
                int ncol = c + delCol[i];

                // Boundary check + Rasta khula hai (grid == 0) + Chota distance mil raha hai
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < n && grid[nrow][ncol] == 0 && dist[r][c] + 1 < dist[nrow][ncol]) {
                    
                    dist[nrow][ncol] = dist[r][c] + 1;
                    
                    // Jaise hi destination par pahuche, turant answer return kar do
                    if (nrow == n - 1 && ncol == n - 1) {
                        return dist[nrow][ncol];
                    }
                    
                    q.push({nrow, ncol});
                }
            }
        }

        return -1; // Agar destination tak pahunchne ka koi raasta na mile
    }
};