class Solution {
public:
    string longestCommonPrefix(vector<string> &str) {
        int n = str.size();
        if (n == 0) return "";
        string res = "";
        sort(begin(str), end(str));
        
        string first = str[0];
        string second = str[n - 1];
        for (int i = 0; i < first.size(); i++) {
            if (first[i] == second[i]) {
                res = res + first[i];
            } else break;
        }
        return res;
    }
};