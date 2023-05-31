class UndergroundSystem {
public:
    unordered_map<int, pair<string, int>> mp; // <cust, <from, time> >
    map<pair<string, string>, pair<int, int>> avg; // < <from, to>, <time, count> > >
    
    UndergroundSystem() {}
    
    void checkIn(int id, string from, int start) {
        mp[id] = {from, start};
    }
    
    void checkOut(int id, string to, int t) {
        auto x = mp[id];
        pair<string, string> key = make_pair(x.first, to);
        if(avg.find(key) != avg.end()) {
            auto prev = avg[key];
            prev.first += (t - x.second);
            prev.second ++;
            avg[key] = prev;
        }
        else {
            avg[key] = make_pair(t - x.second, 1);
        }
    }
    
    double getAverageTime(string start, string end) {
        pair<string, string> key = make_pair(start, end);
        auto res = avg[key];
        return res.first / (1.0 * res.second);      
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */