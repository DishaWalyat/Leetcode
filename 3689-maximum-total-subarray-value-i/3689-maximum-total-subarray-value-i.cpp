class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int maxi=0; 
        int mini= INT_MAX;
        long long sum=0;

        for(int i=0; i<nums.size(); i++){
            maxi=max(maxi,nums[i]);
            mini=min(mini,nums[i]);
        }
        sum = maxi-mini;
        return (sum*k);
        
    }
};