class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {

        int n = nums.size();

        vector<int> leftsum(n, 0);
        vector<int> rightsum(n, 0);

        int sum = 0;

        for(int i = 0; i < n; i++) {
            leftsum[i] = sum;   // sum before current index
            sum += nums[i];
        }

        int sum2 = 0;

        for(int i = n - 1; i >= 0; i--) {
            rightsum[i] = sum2; 
            sum2 += nums[i];
        }

        vector<int> result(n);

        for(int i = 0; i < n; i++) {
            result[i] = abs(leftsum[i] - rightsum[i]);
        }

        return result;
    }
};