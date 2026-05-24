class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        for(int i =0;i< nums.size(); i ++){
            int goal= target-nums[i];
            if( mp.find(goal) != mp.end()){
                return{i, mp[goal]};
            }
            mp[nums[i]]=i;
        }
        return {};
    }
};

//BRUTE FORCE;
// for( int i =0; i <nums.size(); i ++ ){
//             for( int j=i+1; j<size; j++){
//                 if( nums[i]+ nums[j] == target){
//                     return {i,j};
//                 }
//             }
//         }