class Solution {
public:
    vector<int> partitionLabels(string s) {
        int l = 0;
        int r = 0;
        int n = s.size();
        unordered_map<char, int> mp;
        vector<int> res;
        for(char c : s) mp[c]++;
        while(r < n) {
            unordered_set<char> st;
            st.insert(s[r]);
            while(!st.empty()) {
                st.insert(s[r]);
                mp[s[r]]--;
                if(mp[s[r]] == 0) {
                    st.erase(s[r]);
                }
                r++;
            }
            res.emplace_back(r-l);
            l=r;
        }
        return res;
    }
};