class Solution {
public:

    vector<int> parent;

    int find(int x) {
        if (parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        int n = edges.size();

        parent.resize(n + 1);

        // Initially every node is its own parent
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }

        for (auto edge : edges) {

            int u = edge[0];
            int v = edge[1];

            int pu = find(u);
            int pv = find(v);

            // Already connected → cycle
            if (pu == pv) {
                return {u, v};
            }

            // Merge the two components
            parent[pu] = pv;
        }

        return {};
    }
};