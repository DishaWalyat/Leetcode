class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {

        //pivot ke hisaab se usse chote elemenmt ek taraf 

        vector<int> smaller;
        vector<int> larger;
        vector<int> equal;
        vector<int> merge;

        for( int i =0 ; i <nums.size(); i ++){
            if(nums[i]< pivot){
                smaller.push_back(nums[i]);
            }

            if(nums[i]> pivot){
                larger.push_back(nums[i]);
            }

            if(nums[i]== pivot){
                equal.push_back(nums[i]);
            }
        }

        int n = smaller.size();
        int m =larger.size(); 
        int k= equal.size();

        for( int i =0; i< n; i++){
            merge.push_back(smaller[i]);
        }

        for( int i =0; i< k; i++){
            merge.push_back(equal[i]);
        } 

        for(int i=0; i <m; i ++){
            merge.push_back(larger[i]);
        }

        return merge;


    }
};