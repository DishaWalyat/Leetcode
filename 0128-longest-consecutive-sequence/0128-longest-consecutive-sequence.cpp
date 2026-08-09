class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        if(nums.size() == 0)
            return 0;

        sort(nums.begin(), nums.end());

        int longest = 1;
        int curr = 1;

        for(int i = 1; i < nums.size(); i++) {

            if(nums[i] == nums[i-1])
                continue;                     // ignore duplicates

            else if(nums[i] == nums[i-1] + 1)
                curr++;                       // extend streak

            else {
                longest = max(longest, curr);
                curr = 1;                     // reset
            }
        }

        longest = max(longest, curr);

        return longest;
    }
};