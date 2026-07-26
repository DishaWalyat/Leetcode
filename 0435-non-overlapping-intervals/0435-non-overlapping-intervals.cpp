class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        //calculate the non overlapping intervals 
        sort(intervals.begin(), intervals.end());
        vector<int>prev= intervals[0];
        int count=0;

        for(int i=1; i<intervals.size(); i++){
           if (intervals[i][0] < prev[1]) {
                // Merge overlapping intervals
                count++;
                if(intervals[i][1] < prev[1])
                {
                    prev = intervals[i];
                }

            } else {
                prev = intervals[i];
            }
        }

        return count;
    }
};