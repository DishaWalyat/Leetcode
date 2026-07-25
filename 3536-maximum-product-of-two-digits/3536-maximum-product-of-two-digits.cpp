class Solution {
public:
    int maxProduct(int n) {
        int product=1;
        int max1=0;
        int max2=0;

        while(n>0){
            int temp= n%10;
            n=n/10;
            if(temp>=max1){
                max2=max1;
                max1=temp;
            }else if(temp>max2){
                max2=temp;
            }
        }
      return max1*max2;
    }
};