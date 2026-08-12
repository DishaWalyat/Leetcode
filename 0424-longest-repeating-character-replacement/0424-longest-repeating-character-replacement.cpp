class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> freq;

        int i = 0;
        int maxFreq = 0;
        int maxi = 0;

        for (int j = 0; j < s.size(); j++) {
            freq[s[j]]++;

            // update max frequency
            maxFreq = max(maxFreq, freq[s[j]]);

            // check if window is invalid
            while ((j - i + 1) - maxFreq > k) {
                freq[s[i]]--;
                i++;
            }

            // update answer
            maxi = max(maxi, j - i + 1);
        }

        return maxi;
    }
};