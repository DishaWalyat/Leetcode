class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> nge(n, -1);
        stack<int> st; // Decreasing order maintain karega (sirf values store karenge)

        // Ulti ginti shuru: 2*n - 1 se 0 tak
        for (int i = 2 * n - 1; i >= 0; i--) {
            int idx = i % n; // Circular index

            // Step 1: Jo bhi chhote ya barabar elements hain, unhe pop karo
            while (!st.empty() && st.top() <= nums[idx]) {
                st.pop();
            }

            // Step 2: Answer sirf tabhi fill karna hai jab hum asli array me hon (i < n)
            if (i < n) {
                if (!st.empty()) {
                    nge[idx] = st.top();
                } else {
                    nge[idx] = -1;
                }
            }

            // Step 3: Current element ko stack me push karo backup ke liye
            st.push(nums[idx]);
        }
        return nge;
    }
};