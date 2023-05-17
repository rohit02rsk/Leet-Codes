class BrowserHistory {
public:
    vector<string> vec;
    int curr;
    BrowserHistory(string homepage) {
        vec.push_back(homepage);
        curr = 0;
    }
    
    void visit(string url) {
        curr++;
        if(vec.begin() + curr == vec.end()) vec.push_back(url);
        else {
            vec.erase(vec.begin() + curr, vec.end());
            vec.push_back(url);
        }
    }
    
    string back(int steps) {
        int n = vec.size();
        if(curr - steps < 1) {
            curr = 0;
            return vec[0];
        }
        else {
            curr -= steps;
            return vec[curr];
        }
    }
    
    string forward(int steps) {
        int n = vec.size();
        if(curr + steps > n-1) {
            curr = n-1;
            return vec[n-1];
        }
        else {
            curr += steps;
            return vec[curr];
        }
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */