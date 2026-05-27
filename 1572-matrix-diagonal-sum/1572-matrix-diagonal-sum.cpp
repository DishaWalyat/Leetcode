class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {

        int n = mat.size();

        int sum = 0;

        for(int i = 0; i < n; i++) {

            // primary diagonal
            sum += mat[i][i];

            // secondary diagonal
            sum += mat[i][n - i - 1];
        }

        // remove double counted middle element
        if(n % 2 == 1) {

            sum -= mat[n/2][n/2];
        }

        return sum;
    }
};