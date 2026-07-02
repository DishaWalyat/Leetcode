class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        // 1. Bank ke saare elements ko HashSet mein daal do taaki O(1) mein search ho sake
        unordered_set<string> bankSet(bank.begin(), bank.end());
        
        // Agar endGene bank mein hi nahi hai, toh rasta banna namumkin hai
        if (bankSet.find(endGene) == bankSet.end()) return -1;
        
        // 2. BFS ke liye Queue aur visited set banao
        queue<string> q;
        q.push(startGene);
        
        unordered_set<string> visited;
        visited.insert(startGene);
        
        int mutations = 0; // Steps counter
        
        // Char characters jo allow hain DNA mein
        vector<char> choices = {'A', 'C', 'G', 'T'};
        
        // 3. BFS Loop
        while (!q.empty()) {
            int size = q.size();
            
            // Ek level ke saare genes ko ek saath process karo
            for (int i = 0; i < size; i++) {
                string curr = q.front();
                q.pop();
                
                // Agar target mil gaya, toh yahi minimum steps hain
                if (curr == endGene) return mutations;
                
                // Is current string ke har ek character ko badal kar dekho
                for (int j = 0; j < 8; j++) {
                    char originalChar = curr[j];
                    
                    for (char c : choices) {
                        curr[j] = c; // Mutate kiya
                        
                        // Agar naya gene bank mein hai aur pehle visit nahi hua
                        if (bankSet.find(curr) != bankSet.end() && visited.find(curr) == visited.end()) {
                            visited.insert(curr);
                            q.push(curr);
                        }
                    }
                    curr[j] = originalChar; // Backtrack/Revert back to original for next position
                }
            }
            mutations++; // Ek level khatam, matlab ek mutation step badh gaya
        }
        
        return -1; // Agar queue khaali ho gayi aur endGene nahi mila
    }
};