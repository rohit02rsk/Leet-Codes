class Solution {
public:
    vector<int> dp;
    int help(string& s, unordered_map<string, int>& mp, int i) {
        if (i >= s.size())
            return 0;
        if (dp[i] != -1)
            return dp[i];
        string curr = "";
        int res = s.size();
        
        for (int ind = i; ind < s.size(); ind++) {
            curr += s[ind];
            int tmp = (mp.count(curr) ? 0 : curr.size());
            int tmp1 = help(s, mp, ind + 1);
            res = min(res, tmp + tmp1);
        }

        return dp[i] = res;
    }
    
    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_map<string, int> mp;
        dp.resize(s.size(), -1);
        for (auto st : dictionary) mp[st]++;
        return help(s, mp, 0);
    }
};