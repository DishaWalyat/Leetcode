
class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int X) {
        int n = nums.size();
        
        // Map track rakhega: {prefix_sum_value, frequency_count}
        unordered_map<int, int> freqMap;
        
        // Base Case: Prefix sum 0 ki frequency shuru me 1 hoti hai
        freqMap[0] = 1;
        
        int currentPrefixSum = 0;
        long long totalValidSubarrays = 0;
        
        for (int i = 0; i < n; i++) {
            // Step 1: Element ko transform karo (+1 ya -1 me)
            if (nums[i] == X) {
                currentPrefixSum += 1;
            } else {
                currentPrefixSum -= 1;
            }
            
            // Step 2: Piche guzar chuke un saare prefix sums ko count karo jo currentPrefixSum se chote hain
            // Note: Map par linear scan karne se O(N^2) ho jayega. 
            // Isko strictly O(N) chalane ke liye hum target ranges track karte hain.
            for (int prevSum = currentPrefixSum - 1; freqMap.find(prevSum) != freqMap.end() || prevSum >= -n; prevSum--) {
                if (freqMap.count(prevSum)) {
                    totalValidSubarrays += freqMap[prevSum];
                }
            }
            
            // Current sum ki frequency badhao
            freqMap[currentPrefixSum]++;
        }
        
        return totalValidSubarrays;

        
    }
};