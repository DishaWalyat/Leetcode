class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {

        unordered_set<int> st;

        for(int i = 0; i < nums.size(); i++){

            // duplicate found
            if(st.find(nums[i]) != st.end()){

                return true;
            }

            st.insert(nums[i]);
        }

        return false;
    }
};