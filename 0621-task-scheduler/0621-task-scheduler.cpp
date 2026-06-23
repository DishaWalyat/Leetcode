class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // Step 1: Har character ki frequency count karo (A-Z)
        vector<int> freq(26, 0);
        for (char ch : tasks) {
            freq[ch - 'A']++;
        }

        // Step 2: Frequencies ko Max-Heap me push karo
        priority_queue<int> maxHeap;
        for (int f : freq) {
            if (f > 0) {
                maxHeap.push(f);
            }
        }

        int totalTime = 0;

        // Step 3: Simulation cycle chalayenge
        while (!maxHeap.empty()) {
            vector<int> temp;
            int timeSpent = 0;

            // Ek cooling cycle ki capacity (n + 1) slots hoti hai
            for (int i = 0; i <= n; i++) {
                if (!maxHeap.empty()) {
                    temp.push_back(maxHeap.top() - 1); // Task perform kiya, freq kam ki
                    maxHeap.pop();
                    timeSpent++;
                }
            }

            // Jo tasks abhi bhi bache hain (freq > 0), unhe wapas queue me bhejo
            for (int f : temp) {
                if (f > 0) {
                    maxHeap.push(f);
                }
            }

            // Agar heap abhi bhi bhari hai, matlab cooling window me bacha time IDLE tha
            // Agar heap khali ho gayi, toh sirf actual timeSpent judega (no trailing idles)
            totalTime += maxHeap.empty() ? timeSpent : (n + 1);
        }

        return totalTime;
    }
};