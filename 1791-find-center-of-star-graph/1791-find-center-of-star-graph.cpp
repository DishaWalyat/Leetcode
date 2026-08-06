class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {

        unordered_map<int, vector<int>> adj;

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int n = edges.size() + 1;

        for (auto &it : adj) {
            if (it.second.size() == n - 1)
                return it.first;
        }

        return -1;
    }
};