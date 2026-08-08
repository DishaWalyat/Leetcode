class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        //steps: 1. first build the right side characters match count vector
        // 2. then use two pointers and iterate through the word, while keeping the check of change power and right side char match
        vector<int> rightHandMatchLen(n,0);
        int match=0;
        int i=n-1, j=m-1;
        while(i>=0){
            if(j>=0 && word1[i]==word2[j]){
                match++;
                j--;
            }
            rightHandMatchLen[i]=match;
            i--;
        }
        vector<int> seq;
        bool canChange=true;
        i=0; j=0;
        while(i<n && j<m){
            if(word1[i]==word2[j]){
                seq.push_back(i);
                j++;
            }
            else if(canChange==true && i+1<n && rightHandMatchLen[i+1]>=m-j-1){
                seq.push_back(i);
                j++;
                canChange=false;
            }
            i++;
        }

        return (j==m) ? seq : vector<int>();
    }
};