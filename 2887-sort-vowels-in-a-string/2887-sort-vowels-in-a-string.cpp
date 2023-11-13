class Solution {
public:
    bool isVowel(char c) {
        bool up = (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
        bool lo = (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
        return up or lo;
    }
    string sortVowels(string s) {
        vector<int> vow;
        string res = "";
        for (int i=0; i<s.size(); i++) {
            if (isVowel(s[i])) {
                vow.push_back(s[i]);
            }
        }
        sort(vow.begin(), vow.end());
        queue<int> vowels;
        for (int i : vow) vowels.push(i);
        for (int i=0; i<s.size(); i++) {
            if (isVowel(s[i])) {
                res += vowels.front();
                vowels.pop();
            } else {
                res += s[i];
            }
        }
        return res;
    }
};