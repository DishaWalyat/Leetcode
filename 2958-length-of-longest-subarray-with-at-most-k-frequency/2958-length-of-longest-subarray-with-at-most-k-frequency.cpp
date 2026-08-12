class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        // sliding window+ hashmap
        unordered_map<int, int>mp;
        int left=0;
        int size=0;
        for(int right=0; right<nums.size(); right++){
            mp[nums[right]]++;
            while(mp[nums[right]]>k){
                mp[nums[left]]--;
                left++;
            }
            size=max(size, right-left+1);
        }
    return size;

    }
};