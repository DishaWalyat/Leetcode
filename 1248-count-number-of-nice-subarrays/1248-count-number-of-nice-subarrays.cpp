class Solution {
public:
    int atMost(vector<int>& nums, int k) {
    int left = 0;
    int ans = 0;
    int odd = 0;

    for(int right = 0; right < nums.size(); right++) {

        if(nums[right] % 2 == 1)
            odd++;

        while(odd > k) {
            if(nums[left] % 2 == 1)
                odd--;

            left++;
        }

        ans += right - left + 1;
    }

    return ans;
}
    int numberOfSubarrays(vector<int>& nums, int k) {
        // unordered_map<int,int> mp;
        // mp[0] = 1;

        // int sum = 0, ans = 0;

        // for(int x : nums) {
        //     sum += x % 2;

        //     if(mp.count(sum - k))
        //         ans += mp[sum - k];

        //     mp[sum]++;
        // }

        // return ans;

        // since we have to find exact number of nice elements, so we need to do the atmost trick

         return atMost(nums, k) - atMost(nums, k - 1);
    }
};