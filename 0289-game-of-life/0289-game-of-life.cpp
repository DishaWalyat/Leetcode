class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {

        int m = board.size();
        int n = board[0].size();

        int dir[8][2] = {
            {-1,-1}, {-1,0}, {-1,1},
            {0,-1},          {0,1},
            {1,-1}, {1,0}, {1,1}
        };

        // Pass 1: Encode transitions
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                int live = 0;

                for (auto &d : dir) {
                    int x = i + d[0];
                    int y = j + d[1];

                    if (x >= 0 && x < m &&
                        y >= 0 && y < n &&
                        (board[x][y] == 1 || board[x][y] == -1))
                        live++;
                }

                if (board[i][j] == 1) {
                    if (live < 2 || live > 3)
                        board[i][j] = -1;
                }
                else {
                    if (live == 3)
                        board[i][j] = 2;
                }
            }
        }

        // Pass 2: Finalize
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (board[i][j] == -1)
                    board[i][j] = 0;
                else if (board[i][j] == 2)
                    board[i][j] = 1;
            }
        }
    }
};