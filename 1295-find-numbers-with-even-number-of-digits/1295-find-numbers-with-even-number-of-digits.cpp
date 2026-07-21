class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans=0;

        for(int i=0; i<nums.size(); i++){
            int sz= (to_string(nums[i]).length());
            if(sz%2==0) ans+=1; 
        }

        return ans;
        
    }
};