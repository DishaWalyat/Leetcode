class Solution {
public:
    bool checkDivisibility(int k) {
        int sum=0;
        int product=1;
        int n=k;
        while(n>0){
            int i= n%10;
            n=n/10;
            product*=i;
            sum+=i;
        }
        if(k% (product+sum) ==0) return true;
        return false;
    }
};