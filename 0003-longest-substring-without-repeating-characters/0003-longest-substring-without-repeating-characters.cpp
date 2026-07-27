class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> freq;
        
        int i = 0, j = 0;
        int maxi = 0;

        while (j < s.size()) {
            
            freq[s[j]]++;

            while (freq[s[j]] > 1) {
                freq[s[i]]--;
                i++;
            }

            
            maxi = max(maxi, j - i + 1);

            j++;
        }

        return maxi;
    }
};