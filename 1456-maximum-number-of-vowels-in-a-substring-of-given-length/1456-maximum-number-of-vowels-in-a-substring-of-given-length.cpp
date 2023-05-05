class Solution {
public:
    bool checkVowel(char c) {
        if(c == 'a') return true;
        if(c == 'e') return true;
        if(c == 'i') return true;
        if(c == 'o') return true;
        if(c == 'u') return true;
        return false;
    }
    
    int maxVowels(string s, int k) {
        int l=0, r=0;
        int res=0, temp=0;
        
        while(r < s.size()) {
            if(checkVowel(s[r])) temp++;
            if(r-l+1 > k) {
                if(checkVowel(s[l])) temp--;
                l++;
            }
            res = max(res, temp);
            r++;
        }
        
        return res;
    }
};