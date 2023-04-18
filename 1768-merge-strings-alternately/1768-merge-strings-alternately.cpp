class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string res = "";
        int len = min(word1.length(), word2.length());
        int i=0;
        for(; i<len; i++) {
            res += word1[i];
            res += word2[i];
        }
        if(word1.length() < word2.length()) {
            while(i<word2.length()) {
                res += word2[i];
                i++;
            }
        } else {
            while(i<word1.length()) {
                res += word1[i];
                i++;
            }
        }
        return res;
    }
};