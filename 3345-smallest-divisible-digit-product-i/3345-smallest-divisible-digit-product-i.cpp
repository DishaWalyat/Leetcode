class Solution {
public:
    int prod(int nu){
        int p=1;
        while(nu>0){
            p*=(nu%10);
            nu/=10;
        }
        return p;
    }
    int smallestNumber(int n, int t) {
        for(int i=n;i<=n+10;i++){
            if(prod(i)%t==0) return i;
        }
        return n;
    }
};