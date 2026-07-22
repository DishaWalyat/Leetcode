class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if (ransomNote.length() > magazine.length()) return false;

        unordered_map<char, int> mp1;

        for (int i = 0; i < ransomNote.length(); i++) {
            mp1[ransomNote[i]]++;
        }

        for (int i = 0; i < magazine.length(); i++) {
            if (mp1.find(magazine[i]) != mp1.end() && mp1[magazine[i]] > 0) {
                mp1[magazine[i]]--;
            }
        }

        for (int i = 0; i < ransomNote.length(); i++) {
            if (mp1[ransomNote[i]] != 0)
                return false;
        }

        return true;
    }
};