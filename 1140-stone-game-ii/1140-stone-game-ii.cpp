class Solution {
public:
    //important game startergy: always play your best in your chance and hope for worst in opponent's chance;
    int n;
    int dp[2][101][101];
    int solveForAlice(vector<int>& piles, int person, int i, int M){
        if(i>=n) return 0;
        if(dp[person][i][M]!=-1) return dp[person][i][M];
        int result=(person==1) ? -1 : INT_MAX; //if alice starts then -1 o/w int-max because we take min in that
        int stones=0;

        for(int x=1;x<=min(2*M,n-i);x++){
            stones+=piles[i+x-1];
            if(person==1){
                result=max(result, stones+solveForAlice(piles,0,i+x, max(M,x)));
            }
            else{
                result=min(result,solveForAlice(piles, 1, i+x, max(M,x)));
            }
        }
        return dp[person][i][M]=result;
    }
    int stoneGameII(vector<int>& piles) {
        n=piles.size();
        memset(dp,-1,sizeof(dp));
        return solveForAlice(piles,1,0,1);
    }
};