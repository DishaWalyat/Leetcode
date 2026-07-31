class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {

        vector<vector<int>> merged;

        for (int i = 0; i < intervals.size(); i++) {

            // Current interval is completely before newInterval
            if (intervals[i][1] < newInterval[0]) {
                merged.push_back(intervals[i]);
            }

            // Current interval is completely after newInterval
            else if (intervals[i][0] > newInterval[1]) {
                merged.push_back(newInterval);
                newInterval = intervals[i];
            }

            // Overlapping intervals
            else {
                newInterval[0] = min(newInterval[0], intervals[i][0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);
            }
        }

        merged.push_back(newInterval);

        return merged;
    }
};