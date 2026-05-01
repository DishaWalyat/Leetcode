class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end()); // sorting the two vectors

        int p=0;
        int q=0;// pointers

        while( p < g.size() && q< s.size()){
            if( s[q]>= g[p]){
                q++;
                p++;
            }
            else if( s[q]< g[p]){
                q++;
            }
        }

        return p;



    }
};