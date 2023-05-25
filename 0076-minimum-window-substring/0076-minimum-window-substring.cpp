class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mp;
        for(int i=0; i<t.size(); i++) mp[t[i]]++;
        int l = 0;
        int r = 0;
        int need = t.size();
        int minLen = INT_MAX;
        int startInd = 0;
        
        while(r < s.size()) {
            if(mp[s[r]] > 0) {
                need--;
            }
            mp[s[r]]--;
            r++;
            while(need == 0) {
                if(r - l < minLen) {
                    startInd = l;
                    minLen = r - l;
                }
                mp[s[l]]++;
                if (mp[s[l]] > 0) {
                    need++;
                }
                l++;
            }
        }
        if (minLen != INT_MAX) {
            return s.substr(startInd, minLen);
        }
        return "";
    }
};