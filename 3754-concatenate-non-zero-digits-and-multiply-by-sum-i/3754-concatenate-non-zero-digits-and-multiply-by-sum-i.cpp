class Solution {
public:
    long long sumAndMultiply(int n) {
        long long sum = 0; 
        long long number = 0;
        long long ten = 1; 
        
        string temp = to_string(n);
        
        for (int i = temp.size() - 1; i >= 0; i--) {
            
            
            int digit = temp[i] - '0';
            
            if (digit != 0) {
                sum += digit;
                
                number += digit * ten;
                ten = ten * 10;
            }
        }
        
        
        return number * sum;
    }
};