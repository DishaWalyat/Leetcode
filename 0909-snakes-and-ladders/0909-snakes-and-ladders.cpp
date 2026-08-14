class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
    int n = board.size();

    queue<int> q;
    vector<int> dist(n * n + 1, -1);

    q.push(1);
    dist[1] = 0;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        if (curr == n * n)
            return dist[curr];

        for (int dice = 1; dice <= 6; dice++) {
            int next = curr + dice;

            if (next > n * n)
                continue;

            // Convert square number -> board coordinates
            int x = (next - 1) / n;
            int y = (next - 1) % n;

            if (x % 2 == 1)
                y = n - 1 - y;

            x = n - 1 - x;

            // Snake / ladder
            if (board[x][y] != -1)
                next = board[x][y];

            if (dist[next] == -1) {
                dist[next] = dist[curr] + 1;
                q.push(next);
            }
        }
    }

    return -1;
}
};