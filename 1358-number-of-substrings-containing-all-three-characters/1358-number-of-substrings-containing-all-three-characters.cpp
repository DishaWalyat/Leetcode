class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int i = 0, res = 0;
        vector<int> count(3, 0); 

        for (int j = 0; j < n; j++) {
            count[s[j] - 'a']++;

            while (count[0] > 0 && count[1] > 0 && count[2] > 0) {
                res += (n - j);
                count[s[i] - 'a']--;
                i++;
            }
        }

        return res;
    }
};