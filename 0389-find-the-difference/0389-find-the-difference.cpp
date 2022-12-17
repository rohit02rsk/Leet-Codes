class Solution {
public:
    char findTheDifference(string str, string t) {
        unordered_map<char, int> m;
        for(char c: str) m[c]++;
        for(char c: t) {
            if(m[c] == 0) return c;
            m[c]--;
            if(m[c] < 0) return c;
        }
        return '1';
    }
};