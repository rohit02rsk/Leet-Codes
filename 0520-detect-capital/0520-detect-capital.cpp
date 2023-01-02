class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.length();
        int c = 0;
        for(char ch: word) if(isupper(ch)) c++;
        return c == 0 || c == n || (isupper(word[0]) && c == 1);
    }
};