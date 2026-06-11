class Solution {//4 step code
public:
/*
Story Points:

1. When new element comes nums[i], make space for it (window size can't be greater than k)

2. Now, when nums[i] comes, there is no need to keep small elements in that window, pop them

3. Now push i in deque -> for nums[i]

4. If (i >= k-1), then deq.front() is our answer for that window
*/
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == 0)
            return {};
        deque<int> deq;

        vector<int> result;
        
        for(int i = 0; i<n; i++) {
            //remove the max elements from front which are out of window size
            while(!deq.empty() && deq.front() <= i-k)
                deq.pop_front();
            
            //we maintain the deque in descending order
            while(!deq.empty() && nums[i] > nums[deq.back()])
                deq.pop_back();
            
            deq.push_back(i);

            if(i >= k-1) //Only when the window size first gets equal or greater than k
                result.push_back(nums[deq.front()]); //front will have the max element (dequeue is maintained in descending order)
        }
        return result;
    }
};