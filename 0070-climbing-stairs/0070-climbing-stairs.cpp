class Solution {
public:
    int solve(int n, vector<int>& dp){
        if(n<=2) return n;
        if(dp[n]!= -1) return dp[n];

        return dp[n]= solve(n-1,dp)+ solve(n-2,dp);

    }
    int climbStairs(int n) {
        // if(n==1) return 1;
        // if(n==2) return 2;      TLEE
        // return climbStairs(n-1)+climbStairs(n-2); 

        // if( n<=2) return n;

        // int c;
        // int a=1;  
        // int b=2;
        // for(int i=2; i<n; i++ ){    constant space complexity 
        //     c=a+b;
        //     a=b;
        //     b=c;
        // } 
        // return c;

        if( n<= 2) return n;

        vector<int> dp(n+1,-1);

        return solve(n,dp);

    }
};