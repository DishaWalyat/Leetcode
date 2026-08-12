class Solution {
public:
    int numberOfSubstrings(string s) {

        int left = 0;
        int ans = 0;

        unordered_map<char, int> mp;

        for(int right = 0; right < s.size(); right++) {

            mp[s[right]]++;

            while(mp['a'] > 0 &&
                  mp['b'] > 0 &&
                  mp['c'] > 0) {

                mp[s[left]]--;
                left++;
            }

            ans += left;
        }

        return ans;
    }
};