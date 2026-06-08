class Solution {
public:

    void dfs(int row,int col, vector<vector<char>>& grid,vector<vector<int>>& visited,int n,int m){
        visited[row][col]=1;

        int delrow[]={-1,0,+1,0};
        int delcol[]={0,+1,0,-1};


        for(int i=0; i <4; i++){
            int drow= row+ delrow[i];
            int dcol= col+ delcol[i];

            if( drow<n && drow>=0 && dcol>=0 && dcol<m && visited[drow][dcol] !=1 && grid[drow][dcol] == '1'){
                dfs(drow, dcol, grid, visited, n,m);
            }
        }

    }




    int numIslands(vector<vector<char>>& grid) {
        // number of island toh ek proper connected components ka question hai
        int island=0;
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>> visited(n, vector<int>(m, 0));

        for( int i=0; i<n; i++){
            for( int j=0; j<m;j++){
                if( grid[i][j]=='1' && visited[i][j] !=1){
                    island++;
                    dfs(i,j,grid,visited,n,m);
                }
            }
        }

        return island;
    }
};