class Solution {
public:
    bool halvesAreAlike(string s) {
        int vow = 0;
        int i = 1, n = s.length();
        for(char c: s) {
            if(tolower(c) == 'a' || tolower(c) == 'e' || tolower(c) == 'i' || tolower(c) == 'o' || tolower(c) == 'u') {
                if(i <= n/2) vow++;
                else vow--;
            }
            i++;
        }
        return vow == 0;
    }
};