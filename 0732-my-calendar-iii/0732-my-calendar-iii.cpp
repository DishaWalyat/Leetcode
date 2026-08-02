class MyCalendarThree {
public:
    map<int,int> sweep;
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {

        sweep[start]++;
        sweep[end]--;

        int active = 0;
        int ans = 0;

        for (auto &it : sweep) {
            active += it.second;
            ans = max(ans, active);
        }

        return ans;  
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */