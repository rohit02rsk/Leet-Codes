
class Solution {
public:
    static bool cmp(pair<string, int>& a, pair<string, int>& b)
    {
        if (a.second > b.second) return a.second > b.second;
        else if (a.second == b.second) return a.first < b.first;
        else return false;
    }     
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        int n = words.size();
        map<string, int> m;
        for(int i=0 ; i<n ; i++) 
            m[words[i]]++;
        
        vector<pair<string, int>> result(m.begin(), m.end());
        sort(result.begin(), result.end(), cmp);
        
        vector<string> r;
        for(int i=0 ; i<k ; i++) 
            r.push_back(result[i].first);
        
        return r;
    }
};