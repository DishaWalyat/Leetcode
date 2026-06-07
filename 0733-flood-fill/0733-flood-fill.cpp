class Solution {
public:
    void dfs(int row, int col, vector<vector<int>>& ans, int newColor, int delRow[], int delCol[], int iniColor, int n, int m){
        // Saare changes 'ans' matrix me honge, 'image' me nahi
        ans[row][col] = newColor; 

        for(int i = 0; i < 4; i++){
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];
           
            // 1. ncol < m kiya (kyunki columns m hain)
            // 2. check bhi 'ans' matrix par hi kiya
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && ans[nrow][ncol] == iniColor){
                dfs(nrow, ncol, ans, newColor, delRow, delCol, iniColor, n, m);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int iniColor = image[sr][sc];
        
        // Agar starting cell ka rang pehle se hi target color hai, toh kuch karne ki zaroorat nahi hai
        if (iniColor == color) return image; 

        int n = image.size();
        int m = image[0].size();

        vector<vector<int>> ans = image; // Copy banayi

        int delRow[] = {-1, 0, +1, 0};
        int delCol[] = {0, +1, 0, -1};

        // DFS call kiya (n aur m ko baar-baar calculate karne ke bajay yahan se pass kar diya)
        dfs(sr, sc, ans, color, delRow, delCol, iniColor, n, m);
        
        return ans;
    }
};