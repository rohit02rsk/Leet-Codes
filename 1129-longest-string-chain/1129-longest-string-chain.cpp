class Solution {
public:
    static bool cmp(const string &s1, const string &s2) {
        return s1.size() < s2.size();
    }

    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), cmp);
        unordered_map<string, int> mp;
        int res = 0;
        for (auto w : words) {
            int longest=0;
            for (int i = 0; i < w.size(); i++) {
                string sub = w;
                sub.erase(i, 1);
                longest = max(longest, mp[sub]+1);
            }
            mp[w] = longest;
            res = max(res, longest);
        }
        return res;
    }
};