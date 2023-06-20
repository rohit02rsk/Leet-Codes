class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        vector<vector<string>> res;
        for(auto& str : strs) {
            auto temp = str;
            sort(temp.begin(), temp.end());
            mp[temp].emplace_back(str);
        }
        for(auto& it : mp) 
            res.emplace_back(it.second);
        return res;
    }
};