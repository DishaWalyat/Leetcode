class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n=nums.size();
        int closestSum=10000000;
        sort(nums.begin(), nums.end());
        for(int k=0; k <=n-3; k++){
            int i=k+1;
            int j=n-1;
            
            while(j>i){
                int sum= nums[k]+nums[i]+nums[j];
                if(abs(target-sum)<abs(target-closestSum)){
                    closestSum=sum;

                }
                if(sum<target) i++;
                else{
                    j--;
                }
            }
        
        }
        return closestSum;
        

    }
};