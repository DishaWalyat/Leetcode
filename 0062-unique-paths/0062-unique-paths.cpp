class Solution {
public:
    int uniquePaths(int m, int n) {
    long long ans = 1;

    int total = m + n - 2;
    int choose = min(m - 1, n - 1);

    for(int i = 1; i <= choose; i++) {
        ans = ans * (total - choose + i) / i;
    }

    return (int)ans;
}
};