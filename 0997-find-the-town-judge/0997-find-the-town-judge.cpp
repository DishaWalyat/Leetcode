class Solution {
public:
    void DFS(int i,
             vector<int>& indegree,
             vector<int>& outdegree,
             vector<bool>& visited,
             unordered_map<int, vector<int>>& adj) {

        visited[i] = true;

        for (int j : adj[i]) {
            outdegree[i]++;
            indegree[j]++;

            if (!visited[j])
                DFS(j, indegree, outdegree, visited, adj);
        }
    }

    int findJudge(int n, vector<vector<int>>& trust) {

        unordered_map<int, vector<int>> adj;

        vector<int> indegree(n + 1, 0);
        vector<int> outdegree(n + 1, 0);
        vector<bool> visited(n + 1, false);

        for (auto &t : trust)
            adj[t[0]].push_back(t[1]);

        for (int i = 1; i <= n; i++) {
            if (!visited[i])
                DFS(i, indegree, outdegree, visited, adj);
        }

        for (int i = 1; i <= n; i++) {
            if (indegree[i] == n - 1 && outdegree[i] == 0)
                return i;
        }

        return -1;
    }
};