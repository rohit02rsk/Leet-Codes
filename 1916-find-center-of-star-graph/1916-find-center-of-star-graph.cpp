class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_set<int> s;
        for(auto x: edges) {
            if(s.count(x[0])) return x[0];
            if(s.count(x[1])) return x[1];
            s.insert(x[0]);
            s.insert(x[1]);
        }
        return 0;
    }
};