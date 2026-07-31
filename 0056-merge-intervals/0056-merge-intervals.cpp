class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> result;
        vector<int>prev;

        prev=intervals[0];

        for( int i=1; i<intervals.size(); i++){
            if(intervals[i][0]<= prev[1]){
                prev[1]= max(intervals[i][1], prev[1]);
            }
            else{
                result.push_back(prev);
                prev= intervals[i];
        
            }
        }

         result.push_back(prev);

        return result;

        
    }
};