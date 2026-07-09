
class Solution {
private:
    // Global or member variable to store the triplets, as implied by result.clear()
    vector<vector<int>> result;

    // Two-pointer helper function to find n2 and n3
    void twoSum(vector<int>& nums, int target, int i, int j) {
        int n1 = -target; // The fixed element we started with
        
        while (i < j) {
            int current_sum = nums[i] + nums[j];
            
            if (current_sum > target) {
                j--; // Need a smaller sum, move right pointer left
            } 
            else if (current_sum < target) {
                i++; // Need a larger sum, move left pointer right
            } 
            else {
                // Found a valid triplet: {n1, n2, n3}
                result.push_back({n1, nums[i], nums[j]});
                
                // Skip duplicate values for the second element (n2)
                while (i < j && nums[i] == nums[i + 1]) {
                    i++;
                }
                // Skip duplicate values for the third element (n3)
                while (i < j && nums[j] == nums[j - 1]) {
                    j--;
                }
                
                // Move both pointers inward after finding a valid match
                i++;
                j--;
            }
        }
    }

public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        
        if (n < 3) {
            return {};
        }
        
        result.clear();
        
        // Step 1: Sort the array to use the two-pointer technique
        sort(nums.begin(), nums.end());
        
        // Step 2: Fix one element (n1) and search for the other two
        for (int i = 0; i <= n - 3; i++) {
            
            // Skip duplicates for the first element (n1) to avoid duplicate triplets
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            
            int n1 = nums[i];
            int target = -n1; // Since n1 + n2 + n3 = 0 -> n2 + n3 = -n1
            
            // Look for n2 and n3 in the remaining sorted subarray [i+1, n-1]
            twoSum(nums, target, i + 1, n - 1);
        }
        
        return result;
    }
};