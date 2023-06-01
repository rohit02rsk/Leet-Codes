class Solution {
public:
    bool help(string& s, unsigned long long int prev, int pos) {
        if(pos == s.size()) {
            return true;
        }
        for(int i=pos; i<s.size(); i++) {
            string t = s.substr(pos, i-pos+1);
            unsigned long long int temp = stoull(t);
            if((temp + 1 == prev) and help(s, temp, i+1))
                return true;
        }
        return false;
    }
    bool splitString(string s) {
        string t = "";
        for(int i=0; i<s.size()-1; i++) {
            t += s[i];
            unsigned long long int temp = stoull(t);
            if(help(s, temp, i+1)) 
                return true;
        }
        return false;
    }
};