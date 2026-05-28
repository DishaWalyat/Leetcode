class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());

        int n = nums.size();

        for(int i = 0; i < n; i++){

            // skip duplicates for i
            if(i > 0 && nums[i] == nums[i-1]){
                continue;
            }

            for(int j = i+1; j < n; j++){

                // skip duplicates for j
                if(j > i+1 && nums[j] == nums[j-1]){
                    continue;
                }

                int left = j + 1;
                int right = n - 1;

                while(left < right){

                    long long sum =
                    (long long)nums[i]
                    + nums[j]
                    + nums[left]
                    + nums[right];

                    // quadruplet found
                    if(sum == target){

                        ans.push_back({
                            nums[i],
                            nums[j],
                            nums[left],
                            nums[right]
                        });

                        // skip duplicates
                        while(left < right &&
                              nums[left] == nums[left+1]){

                            left++;
                        }

                        while(left < right &&
                              nums[right] == nums[right-1]){

                            right--;
                        }

                        left++;
                        right--;
                    }

                    // need bigger sum
                    else if(sum < target){

                        left++;
                    }

                    // need smaller sum
                    else{

                        right--;
                    }
                }
            }
        }

        return ans;
    }
};