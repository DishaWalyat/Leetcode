class Solution {
public:
    int t[502][502];
    int solve( int i, int j, vector<int>& piles){
        if(i>j) return 0;
        if(i==j) return piles[i];

        if( t[i][j] !=-1) return t[i][j];

        int first= piles[i]+ min(solve(i+2, j, piles), solve(i+1, j-1, piles));
        int second= piles[j]+ min(solve(i, j-2, piles), solve(i+1, j-1, piles));

        return t[i][j]= max(first, second);
    }

    bool stoneGame(vector<int>& piles) {
        memset(t,-1, sizeof(t));
        int n= piles.size();

        int total_score= accumulate(begin(piles), end(piles),0);
        
        int alice= solve(0,n-1, piles);
        int bob= total_score- alice;

        return alice>= bob;
        
    }
};