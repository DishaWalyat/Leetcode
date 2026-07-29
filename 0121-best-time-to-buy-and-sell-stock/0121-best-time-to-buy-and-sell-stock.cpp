class Solution {
public:
    int maxProfit(vector<int>& prices) {

        // first we need to find the minimum element then followed by the highest 
        int maxProfit=0;
        int mini= prices[0];

        for(int i=0; i <prices.size(); i++){
            int profit= prices[i]- mini;
            maxProfit=max(maxProfit, profit);
            mini= min(mini, prices[i]);
        }

        return maxProfit;
        
    }
};