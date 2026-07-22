class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp1;
        unordered_map<int,int> mp2;
        vector<int> result;

        for(int i = 0; i < nums1.size(); i++){
            mp1[nums1[i]]++;      // Changed from mp1[i]
        }

        for(int i = 0; i < nums2.size(); i++){
            mp2[nums2[i]]++;      // Changed from mp2[i]
        }

        for(int i = 0; i < nums1.size(); i++){
            if(mp2.find(nums1[i]) != mp2.end() && mp2[nums1[i]] > 0){
                result.push_back(nums1[i]);
                mp2[nums1[i]]--;   // Decrease frequency
            }
        }

        return result;
    }
};