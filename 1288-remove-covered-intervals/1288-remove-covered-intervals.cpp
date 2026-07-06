
class Solution {
public:
    int removeCoveredIntervals(std::vector<std::vector<int>>& intervals) {
        // 1. Sort: Start points ascending. If they match, end points descending.
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& a_next) {
            if (a[0] == a_next[0]) {
                return a[1] > a_next[1]; // Descending end
            }
            return a[0] < a_next[0]; // Ascending start
        });
        
        int count = 0;
        int max_end = 0;
        
        // 2. Linear scan tracking the dominant upper bound
        for (const auto& interval : intervals) {
            int end = interval[1];
            
            // If the current interval extends further than our maximum seen end,
            // it's a new unique/dominant interval (equivalent to a stack push)
            if (end > max_end) {
                count++;
                max_end = end;
            }
        }
        
        return count;
    }
};