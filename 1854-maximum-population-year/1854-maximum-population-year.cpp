class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<pair<int,int>>events;

        for( auto& log: logs){
            events.push_back({ log[0], +1});
            events.push_back({ log[1], -1});

        }

        sort(events.begin(), events.end());

        int currPop=0;
        int maxPop=0;
        int minyear=2050;

        for(auto &e: events){
            currPop+=e.second;
            if(currPop>maxPop){
                maxPop= currPop;
                minyear= e.first;
            }

        }
        return minyear;
    }
};