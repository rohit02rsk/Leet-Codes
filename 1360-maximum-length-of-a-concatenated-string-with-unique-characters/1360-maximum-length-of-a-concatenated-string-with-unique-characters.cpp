class Solution {
public:
    int res = 0;
    int maxLength(vector<string>& arr) {
        help(arr, "", 0);
        return res;
    }
    void help(vector<string>& arr, string curr, int pos) {
        if(!unique(curr)) return;
        if(res < curr.size()) res = curr.size();
        for(int i=pos; i<arr.size(); i++) {
            help(arr, curr+arr[i], i+1);
        }
    }
    bool unique(string s) {
        unordered_set<char> st;
        for(char c: s) {
            if(st.count(c)) 
                return false;
            st.insert(c);
        }
        return true;
    }
};