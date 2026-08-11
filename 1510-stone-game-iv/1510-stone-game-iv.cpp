class Solution {
public:
    vector<int> dp;
    bool solve(int n){
        if(n==0) return false;
        if(dp[n]!=-1){
            if(dp[n]==1) return true;
            else return false;
        }
        for(int k=1;k*k<=n;k++){
            if(solve(n-(k*k))==false) return dp[n]=true; // this was bob chance;
        }
        return dp[n]=false;
    }
    bool winnerSquareGame(int n) {
        dp.assign(n+1,-1);
        return solve(n);
    }
};