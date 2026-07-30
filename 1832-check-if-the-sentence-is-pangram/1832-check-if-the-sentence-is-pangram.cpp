class Solution {
public:
    bool checkIfPangram(string sentence) {
        unordered_map<int,int> mp;
        for( int i=0; i<sentence.length(); i++){
            mp[sentence[i]-'a']++;
        }
        
        for(int i=0; i<26; i++){
            if(mp.find(i) == mp.end()){
                return false;
            }
        }

        return true;


        
    }
};