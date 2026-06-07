class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int ans = 0;
        int n = arr.size();
        int mod = 1e9 + 7;

        vector<int> nextSmaller(n);
        vector<int> prevSmaller(n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }

            nextSmaller[i] = st.empty() ? n : st.top();

            st.push(i);
        }

        while (!st.empty())
            st.pop();

        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }

            prevSmaller[i] = st.empty() ? -1 : st.top();

            st.push(i);
        }

        for (int i = 0; i < n; i++) {
            long long next = nextSmaller[i] - i;
            long long prev = i - prevSmaller[i];

            long long contrib = (arr[i] * next % mod) * prev % mod;

            ans = (ans + contrib) % mod;
        }

        return ans;
    }
};