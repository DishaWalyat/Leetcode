class Solution {
public:
    int climbStairs(int n) {
        // if(n==1) return 1;
        // if(n==2) return 2;      TLEE
        // return climbStairs(n-1)+climbStairs(n-2); 

        if( n<=2) return n;

        int c;
        int a=1;  
        int b=2;
        for(int i=2; i<n; i++ ){
            c=a+b;
            a=b;
            b=c;
        } 
        return c;

    }
};