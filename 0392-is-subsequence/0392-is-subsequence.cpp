class Solution {
public:
    bool isSubsequence(string s, string t) {
        int s_sz = s.size();
        int t_sz = t.size();
        int i = 0;
        int j = 0;
        
        if(s_sz > t_sz)
            return false;

        while(i < s_sz and j < t_sz) {
            if(s[i] == t[j]) {
                i++;
            }
            j++;
        }

        return i == s_sz;
    }
};