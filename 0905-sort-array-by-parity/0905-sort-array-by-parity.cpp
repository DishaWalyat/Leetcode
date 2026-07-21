class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {

        int first = 0;
        int last = nums.size() - 1;

        while (first < last) {

            if (nums[first] % 2 == 0) {
                first++;
            }
            else if (nums[last] % 2 != 0) {
                last--;
            }
            else {
                swap(nums[first], nums[last]);
                first++;
                last--;
            }
        }

        return nums;
    }
};