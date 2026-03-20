class MyCalendar {
public:
    map<int,int>mp;
    MyCalendar() {}

    bool book(int startTime, int endTime) {
        for(auto x:mp){
            int s=x.first;
            int e=x.second;
            //uska end time range me ara hai(>start)
            //uska start time ramge me ara hai(<end)
            if(startTime<e && endTime>s) return false;
        }
        mp[startTime]=endTime;
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */