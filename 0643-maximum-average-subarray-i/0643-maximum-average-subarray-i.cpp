class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        // this is basic sliding window pattern 
        double sum=0;
        // yeh sum hai first window ka(till kth index) 
        for( int i=0; i<k; i++){
            sum+= nums[i];
        }
        
        double maxsum=sum;

        // shift the window
        for( int i=k; i<nums.size(); i++){
            sum+=nums[i];
            sum-=nums[i-k];

            maxsum= max(maxsum, sum);
        }

        return maxsum/k;


        
    }
};