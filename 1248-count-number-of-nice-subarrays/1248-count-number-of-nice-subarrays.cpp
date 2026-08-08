class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        mp[0] = 1;

        int sum = 0, ans = 0;

        for(int x : nums) {
            sum += x % 2;

            if(mp.count(sum - k))
                ans += mp[sum - k];

            mp[sum]++;
        }

        return ans;
    }
};