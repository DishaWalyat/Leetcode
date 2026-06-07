class Solution {
public:
    // Helper function jo boundaries nikal kar total sum deta hai
    long long getContributionSum(vector<int>& arr, bool findMax) {
        int n = arr.size();
        vector<int> left(n), right(n);
        stack<int> st;

        // Pass 1: Left Boundaries (PSE ya PGE)
        for (int i = 0; i < n; i++) {
            // Agar findMax true hai toh Greater check karo, nahi toh Smaller check karo
            while (!st.empty() && (findMax ? arr[st.top()] <= arr[i] : arr[st.top()] >= arr[i])) {
                st.pop();
            }
            left[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop(); // Stack clear kiya

        // Pass 2: Right Boundaries (NSE ya NGE)
        for (int i = n - 1; i >= 0; i--) {
            // Duplicates handle karne ke liye ek taraf strictly '>' ya '<' lagaya
            while (!st.empty() && (findMax ? arr[st.top()] < arr[i] : arr[st.top()] > arr[i])) {
                st.pop();
            }
            right[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        // Total sum calculate karna
        long long total_sum = 0;
        for (int i = 0; i < n; i++) {
            long long L = i - left[i];
            long long R = right[i] - i;
            total_sum += (L * R) * arr[i];
        }
        return total_sum;
    }

    long long subArrayRanges(vector<int>& nums) {
        // Sum of Subarray Maximums - Sum of Subarray Minimums
        return getContributionSum(nums, true) - getContributionSum(nums, false);
    }
};