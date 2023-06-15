class MyCalendar {
public:
    map<int, int> events;
    MyCalendar() {}
    
    bool book(int start, int end) {
        auto it = events.upper_bound(start);
        if(it == events.end() or it->second >= end) {
            events[end] = start;
            return true;
        }
        return false;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */