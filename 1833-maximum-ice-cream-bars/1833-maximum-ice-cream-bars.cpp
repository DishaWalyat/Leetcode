class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {

        int maxi = *max_element(costs.begin(), costs.end());
        vector<int> freq(maxi + 1, 0);

        for (int cost : costs)
            freq[cost]++;

        int ans = 0;

        for (int cost = 1; cost <= maxi; cost++) {
            if (freq[cost] == 0)
                continue;

            int canBuy = min(freq[cost], coins / cost);

            ans += canBuy;
            coins -= canBuy * cost;

            if (coins < cost)
                break;
        }

        return ans;
    }
};