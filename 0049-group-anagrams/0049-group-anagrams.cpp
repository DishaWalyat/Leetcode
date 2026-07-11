class Solution {
public:
    // Helper function that reconstructs the word in sorted order using Counting Sort
    string generate(string& word) {
        int arr[26] = {0};
        
        for(char &ch : word) {
            arr[ch - 'a']++;
        }
        
        string new_word = "";
        
        for(int i = 0; i < 26; i++) {
            int freq = arr[i];
            
            if(freq > 0) {
                // Appends the character (i + 'a') repeated 'freq' times
                new_word += string(freq, i + 'a');
            }
        }
        
        return new_word;
    }
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        
        unordered_map<string, vector<string>> mp;
        
        for(int i = 0; i < n; i++) {
            string word = strs[i];
            // 1. Generate the sorted key for the current word
            string key = generate(word);
            // 2. Group the original word under its key
            mp[key].push_back(word);
        }
        
        // 3. Move the grouped values from the map into the final result matrix
        vector<vector<string>> result;
        for(auto& pair : mp) {
            result.push_back(move(pair.second));
        }
        
        return result;
    }
};