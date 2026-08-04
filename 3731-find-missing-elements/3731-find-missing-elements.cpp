class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int>result;
        int maxi= *max_element(nums.begin(), nums.end());
        int mini= *min_element(nums.begin(), nums.end());
        unordered_map<int, int>mp;
        for(int i=0; i<nums.size(); i++){
            mp[nums[i]]++;
        }

        for(int i=mini; i<maxi; i++){
            if(mp.find(i)!=mp.end()){
                continue;
            }
            else{
                result.push_back(i);
            }
        }
        return result;
    }
};