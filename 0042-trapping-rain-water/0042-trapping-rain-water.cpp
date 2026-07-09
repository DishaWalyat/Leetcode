class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        vector<int> prev(n), next(n), mini(n);

        // prev greatest
        prev[0] = height[0];
        for(int i = 1; i < n; i++) {
            prev[i] = max(prev[i-1], height[i]);
        }

        // next greatest
        next[n-1] = height[n-1];
        for(int i = n-2; i >= 0; i--) {
            next[i] = max(next[i+1], height[i]);
        }

        // min boundary
        for(int i = 0; i < n; i++) {
            mini[i] = min(prev[i], next[i]);
        }

        // water calculation
        int water = 0;
        for(int i = 0; i < n; i++) {
            if(mini[i] > height[i])
                water += mini[i] - height[i];
        }

        return water;
    }
};