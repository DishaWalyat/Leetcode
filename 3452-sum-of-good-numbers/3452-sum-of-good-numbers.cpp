class Solution {
public:
    int sumOfGoodNumbers(vector<int>& nums, int k) {
        int sum = 0;

        for (int i = 0; i < nums.size(); i++) {

            if ((i - k < 0 || nums[i] > nums[i - k]) &&
                (i + k >= nums.size() || nums[i] > nums[i + k])) {
                sum += nums[i];
            }

        }
        return sum;
    }
};