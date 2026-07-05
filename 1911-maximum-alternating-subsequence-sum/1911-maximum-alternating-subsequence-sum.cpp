class Solution {
public:
    int n;
    // Changed from int to long long to prevent overflow
    long long t[100005][2]; 

    long long solve(int idx, vector<int>& nums, bool flag){
        if(idx >= n) return 0;

        if(t[idx][flag] != -1){
            return t[idx][flag];
        }

        long long skip = solve(idx + 1, nums, flag);

        long long val = nums[idx];
        if(flag == false){
            val = -val;
        }
        long long take = solve(idx + 1, nums, !flag) + val;

        return t[idx][flag] = max(take, skip);
    }

    long long maxAlternatingSum(vector<int>& nums) {
        n = nums.size();
        memset(t, -1, sizeof(t)); // Perfectly safe for -1 even with long long!
        return solve(0, nums, true);
    }
};