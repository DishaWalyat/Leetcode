class Solution {
public:

    void dfs(int row, int col,vector<vector<int>>& visited,vector<vector<char>>& board, int n, int m){

        visited[row][col]=1;

        int delrow[]={-1,0,+1,0};
        int delcol[]={0,+1,0,-1};

        for(int i=0; i<4; i++){
            int drow= row+delrow[i];
            int dcol= col+ delcol[i];
        

        if(drow<n && drow>=0 && dcol<m && dcol>=0 && visited[drow][dcol] != 1 && board[drow][dcol] == 'O'){
            dfs(drow, dcol, visited, board,n, m);
        }
    }
}


    void solve(vector<vector<char>>& board) {
        // tu bass chaaro corners pe chala loop aur agar koi O mile toh uspe dfs ya bfs chala ke visited mark karde aur fir end mai match karle jo jo O hai aur visited hai unhe change nhi karna baakiyo ko changeee
        if(board.empty()) return;

       
        int n =board.size();
        int m= board[0].size();

        vector<vector<int>> visited(n, vector<int>(m, 0));

        // 1. Left Boundary (First Column) aur Right Boundary (Last Column)
        for(int i = 0; i < n; i++) {
            // Left Column (Row cambia, Colonna = 0)
            if(board[i][0] == 'O' && !visited[i][0]) {
                dfs(i, 0, visited, board, n, m);
            }
            // Right Column (Row cambia, Colonna = m-1) -> FIXED
            if(board[i][m-1] == 'O' && !visited[i][m-1]) {
                dfs(i, m-1, visited, board, n, m);
            }
        }

        // 2. Top Boundary (First Row) aur Bottom Boundary (Last Row)
        for(int i = 0; i < m; i++) {
            // Top Row (Row = 0, Colonna cambia)
            if(board[0][i] == 'O' && !visited[0][i]) {
                dfs(0, i, visited, board, n, m);
            }
            // Bottom Row (Row = n-1, Colonna cambia) -> FIXED
            if(board[n-1][i] == 'O' && !visited[n-1][i]) {
                dfs(n-1, i, visited, board, n, m);
            }
        }

        // now compare the visited matrix
        for(int i =0; i<n; i ++){
            for( int j=0; j<m; j++){

                if( board[i][j]=='O' && visited[i][j]==0){
                    board[i][j] = 'X';
                }
            }
        }


    }
};