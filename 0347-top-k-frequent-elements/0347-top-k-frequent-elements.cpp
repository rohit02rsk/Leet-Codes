class Solution {
public:
    static bool cmp(pair<int, int> &a, pair<int, int> &b) {
        return a.second > b.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for(int i: nums) m[i]++;
        
        vector<pair<int, int>> arr;
        for(auto &it : m) arr.push_back({it.first, it.second});
        sort(arr.begin(), arr.end(), cmp);
        
        vector<int> res;
        for(int i=0; i<k; i++) res.push_back(arr[i].first);
        return res;
    }
};