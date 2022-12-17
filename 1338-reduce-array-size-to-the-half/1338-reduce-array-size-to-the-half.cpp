
class Solution {
public:
    static bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
       return a.second > b.second;
    }
    int minSetSize(vector<int>& arr) {
        int n = arr.size(); 
        unordered_map<int, int> mp;
        for(int i: arr) mp[i]++;
        
        vector<pair<int, int>> m;
        
        for(auto it: mp)
            m.push_back(make_pair(it.first, it.second));
        
        sort(m.begin(), m.end(), cmp);
        
        int curr = 0, count = 0;
        for(auto x: m) {
            curr += x.second;
            count++;
            if(curr >= (n/2)) return count;
        }
        return count;
    }
};