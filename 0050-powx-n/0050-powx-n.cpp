class Solution {
public:

    double power(double x, long long n){
        if(n == 0) return 1;

        double half = power(x, n/2);

        if(n % 2 == 0)
            return half * half;
        else
            return half * half * x;
}

    double myPow(double x, int n) {
        if(n==0 || x==1.0)return 1; 
        
        
        long long temp = n;

        if(n<0){
            x=1/x;
            temp = -1*1LL*n;
        }

        double ans= power(x, temp);

        return ans;


    }
};