class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> m;
        for(int i=0; i<arr.size(); i++) m[arr[i]]++;
        unordered_set<int> count;
        for(auto x: m) count.insert(x.second);
        return count.size() == m.size();
    }
};