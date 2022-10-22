class Solution {
public:
    string minWindow(string s, string t) {
        map<char, int> m;
        for(auto c: t) m[c]++;
        
        int count = 0;
        int l = 0;
        int min_len = INT_MAX;
        int min_str = 0;
        
        for(int h = 0; h < s.length() ; h++) {
            if(m[s[h]] > 0) count++;
            m[s[h]]--;
            if(count == t.length()) {
                while(l < h and m[s[l]] < 0) {
                    m[s[l]]++;
                    l++;
                }
                if(min_len > h - l) 
                    min_len = h - (min_str = l) + 1;
                m[s[l++]]++;
                count--;
            }
        }
        
        return min_len == INT_MAX ? "" : s.substr(min_str, min_len);
    }
};