class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int j = 0;
        unordered_map<int, int> freq;
        int maxFreq = 0;
        int maxi = 0;

        for (int i = 0; i < nums.size(); i++) {

            freq[nums[i]]++;
            maxFreq = max(maxFreq, freq[1]);  

            while ((i - j + 1) - maxFreq > k) {
                freq[nums[j]]--;
                j++;
            }

            maxi = max(maxi, i - j + 1);
        }

        return maxi;
    }
};