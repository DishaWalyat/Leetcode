class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>st;
        unordered_map<int, int> nge;
        for(int i =0; i < nums2.size(); i++){
            while(!st.empty() && nums2[i]> st.top()){
                nge[st.top()]= nums2[i];
                st.pop();
            }
            st.push(nums2[i]); 

        }
        while (!st.empty()) {
            nge[st.top()] = -1;
            st.pop();
        }

        vector<int> result;
        for (int val : nums1) {
            result.push_back(nge[val]);
        }

        return result;

    }
};