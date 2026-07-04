class Solution {
public:
    int solve(int n, vector<int>& dp){
        if( n<=1 ) return n;

        if( dp[n]!=-1) return dp[n];

        return dp[n]= solve(n-1,dp) + solve(n-2,dp);
    }

    int fib(int n) {
        // recursion mai bahut time waste hai kyunki already jinka resuly nikaal chuke hai woh baar baar karna padhra hai instead isko dp se karengay
        // if (n==0) return n;
        // if (n==1) return n;
        // else{
        //     int ans= fib(n-1)+fib(n-2);
        //     return ans;

        //dp approach
        //linear space complexity

        // if( n<=1 ) return n;

        // int c;
        // int a=0; 
        // int b=1;

        // for( int i=1; i <n; i++){
        //     c=a+b;
        //     a=b;
        //     b=c;
        // }

        // return c;

        // dp 1D array solution
        if( n<=1 ) return n;
        vector<int> dp(n+1,-1);

        return solve(n,dp);
    
    }
};