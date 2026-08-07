class Solution {
public:
    bool checkGoodInteger(int n) {
        int temp=n;
        int squareSum=0;
        int digitSum=0;
        while(temp>0){
            int i=temp%10;
            temp=temp/10;
            squareSum+= i*i;
            digitSum+=i;
        }
        return squareSum - digitSum >= 50;
    }
};