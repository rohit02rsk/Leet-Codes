class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        if(n == 1)
            return {{strs[0]}};
        
        unordered_map<string, vector<string>> mp;
        vector<vector<string>> res;
        
        for(int  i = 0; i < n ; i++) {
            string temp = strs[i];
            sort(strs[i].begin(), strs[i].end());
            mp[strs[i]].push_back(temp);
        }
        
        for(auto itr: mp) {
            res.push_back(itr.second);
        }
        
        return res;
    }
};