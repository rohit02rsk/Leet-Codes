class Solution {
public:
    bool isValid(string s) {
        if(s.size() > 3 or s.size() == 0) return false;
        if(s.size() > 1 and s[0] == '0') return false;
        if(s.size() and stoi(s) > 255) return false;
        return true;
    }
    void help(vector<string>& res, string curr, string s, int dots, int start) {
        if(dots == 3) { 
            if(isValid(s.substr(start)))
                res.push_back(curr + s.substr(start));
            return;
        }
        for(int i=start; i<s.size(); i++) {
            if(isValid(s.substr(start, i+1-start))) {
                curr.push_back(s[i]);
                curr.push_back('.');
                help(res, curr, s, dots+1, i+1);
                curr.pop_back();
            }
        }
        return;
    }
    vector<string> restoreIpAddresses(string s) {
        if(s.size() > 12 or s.size() < 4) return {};
        vector<string> res;
        help(res, "", s, 0, 0);
        return res;
    }
};