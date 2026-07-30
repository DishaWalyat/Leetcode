class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int ans = 0;

        // Fix left column
        for (int left = 0; left < cols; left++) {

            // Stores row sums between left and right
            vector<int> rowSum(rows, 0);

            // Extend right column
            for (int right = left; right < cols; right++) {

                // Update row sums
                for (int r = 0; r < rows; r++) {
                    rowSum[r] += matrix[r][right];
                }

                // LC 560: Count subarrays with sum = target
                unordered_map<int, int> mp;
                mp[0] = 1;

                int prefix = 0;

                for (int x : rowSum) {
                    prefix += x;

                    if (mp.count(prefix - target))
                        ans += mp[prefix - target];

                    mp[prefix]++;
                }
            }
        }

        return ans;
    }
};