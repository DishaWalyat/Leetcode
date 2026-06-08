class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        // Answer aur Visited matrices
        vector<vector<int>> dist(n, vector<int>(m, 0));
        vector<vector<int>> vis(n, vector<int>(m, 0));
        
        // Queue store karega: {{row, col}, steps}
        queue<pair<pair<int, int>, int>> q;
        
        // Step 1: Saare 0s ko dhoondo aur queue me ek sath daal do (Multi-Source!)
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(mat[i][j] == 0) {
                    q.push({{i, j}, 0});
                    vis[i][j] = 1; // 0s pehle se hi visited hain
                }
            }
        }
        
        // Charo directions ke offsets: Up, Right, Down, Left
        int delRow[] = {-1, 0, +1, 0};
        int delCol[] = {0, +1, 0, -1};
        
        // Step 2: Standard BFS standard loop
        while(!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int steps = q.front().second;
            q.pop();
            
            // Current distance ko answer me store karo
            dist[r][c] = steps;
            
            // Charo padosiyon ko check karo
            for(int i = 0; i < 4; i++) {
                int nrow = r + delRow[i];
                int ncol = c + delCol[i];
                
                // Boundary check aur Visited check
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol]) {
                    vis[nrow][ncol] = 1; // Visit mark kiya
                    q.push({{nrow, ncol}, steps + 1}); // Agale step me +1 distance
                }
            }
        }
        
        return dist;
    }
};