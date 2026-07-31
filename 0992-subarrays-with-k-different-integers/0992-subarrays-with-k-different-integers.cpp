class Solution {
public:
    int atMost(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int left = 0;
        int distinct = 0;
        int ans = 0;

        for (int right = 0; right < nums.size(); right++) {

            // Include nums[right]
            if (freq[nums[right]] == 0)
                distinct++;

            freq[nums[right]]++;

            // Shrink until window becomes valid
            while (distinct > k) {
                freq[nums[left]]--;

                if (freq[nums[left]] == 0) {
                    freq.erase(nums[left]);
                    distinct--;
                }

                left++;
            }

            // Count all valid subarrays ending at 'right'
            ans += right - left + 1;
        }

        return ans;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }
};