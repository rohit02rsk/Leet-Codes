class Solution {
public:
    bool palindrome(string s, int i, int j) {
        while(i <= j) {
            if(s[i++] != s[j--]) return false;
        }
        return true;
    }
    void help(vector<vector<string>>& res, vector<string>& curr, int start, string s) {
        if(start == s.size()) {
            res.emplace_back(curr);
            return;
        }
        for(int i=start; i<s.size(); i++) {
            if(palindrome(s, start, i)) {
                curr.emplace_back(s.substr(start, i-start+1));
                help(res, curr, i+1, s);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> curr;
        help(res, curr, 0, s);
        return res;
    }
};