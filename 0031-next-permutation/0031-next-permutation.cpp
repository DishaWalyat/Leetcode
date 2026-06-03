class Solution {
public:
    void nextPermutation(vector<int>& nums) {

        // find pivot 
        int pivot=-1;
        for( int i = nums.size()-2; i >= 0; i--){
            if(nums[i]<nums[i+1]){
                pivot=i;
                break;
            }
        }

        if(pivot == -1){
            reverse(nums.begin(), nums.end());
            return;
        }

        //next greater element after pivot

        int j=-1;
        for(int i=nums.size()-1; i >pivot; i--){
            if(nums[i]>nums[pivot]){
                j=i;
                break;
            }

        }

    

        //swap j and pivot
        swap(nums[j],nums[pivot]);

        // reverse the other half
        reverse(nums.begin()+pivot+1, nums.end());

        
    }
};

