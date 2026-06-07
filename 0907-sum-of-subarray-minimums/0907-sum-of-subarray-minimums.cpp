class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        long long MOD = 1e9 + 7;
        
        vector<int> left(n), right(n);
        stack<int> st;

        // Step 1: Previous Smaller Element (PSE) nikalna
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            // Agar stack khali hai toh left boundary -1, nahi toh st.top()
            left[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        // Stack ko khali karo doosre pass ke liye
        while (!st.empty()) st.pop();

        // Step 2: Next Smaller Element (NSE) nikalna
        for (int i = n - 1; i >= 0; i--) {
            // Yahan strictly '>' use kiya duplicates se bachne ke liye
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            // Agar stack khali hai toh right boundary 'n', nahi toh st.top()
            right[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        // Step 3: Total Sum Calculate karna
        long long total_sum = 0;
        for (int i = 0; i < n; i++) {
            long long L = i - left[i];
            long long R = right[i] - i;
            
            long long total_subarrays = (L * R) % MOD;
            long long contribution = (total_subarrays * arr[i]) % MOD;
            
            total_sum = (total_sum + contribution) % MOD;
        }

        return total_sum;
    }
};