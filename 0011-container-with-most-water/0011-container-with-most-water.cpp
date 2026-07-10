class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int max_water = 0;
        
        while (left < right) {
            // Calculate current width
            int width = right - left;
            
            // Calculate area based on the limiting shorter line
            int current_water =min(height[left], height[right]) * width;
            
            // Keep track of the maximum area seen so far
            max_water = max(max_water, current_water);
            
            // Move the pointer that points to the shorter line
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        
        return max_water;
    }
};