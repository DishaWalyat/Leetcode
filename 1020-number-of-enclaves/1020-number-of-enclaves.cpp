class Solution {
private:
    void dfs(int row, int col, vector<vector<int>>& grid, int n, int m) {
        // very similar toh the surrounding regions, here as well we check the boundries only but return the number if 1 inside
        grid[row][col] = 0; 

        int delrow[] = {-1, 0, +1, 0};
        int delcol[] = {0, +1, 0, -1};

        for(int i = 0; i < 4; i++) {
            int drow = row + delrow[i];
            int dcol = col + delcol[i];

            // Agar padosi grid ke andar hai aur wo bhi land (1) hai, toh aage DFS chalao
            if(drow >= 0 && drow < n && dcol >= 0 && dcol < m && grid[drow][dcol] == 1) {
                dfs(drow, dcol, grid, n, m);
            }
        }
    }

public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        // Step 1: Saare boundary columns (First aur Last Column) ke 1s par DFS chalao
        for(int i = 0; i < n; i++) {
            // First Column
            if(grid[i][0] == 1) {
                dfs(i, 0, grid, n, m);
            }
            // Last Column
            if(grid[i][m-1] == 1) {
                dfs(i, m-1, grid, n, m);
            }
        }

        // Step 2: Saare boundary rows (First aur Last Row) ke 1s par DFS chalao
        for(int i = 0; i < m; i++) {
            // First Row
            if(grid[0][i] == 1) {
                dfs(0, i, grid, n, m);
            }
            // Last Row
            if(grid[n-1][i] == 1) {
                dfs(n-1, i, grid, n, m);
            }
        }

        // Step 3: Ab matrix me jitne bhi 1 bache hain, wo sab andar phanse hue enclaves hain!
        int enclaves_count = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) {
                    enclaves_count++;
                }
            }
        }

        return enclaves_count;
    }
};