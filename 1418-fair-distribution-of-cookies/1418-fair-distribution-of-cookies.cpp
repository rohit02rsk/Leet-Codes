class Solution {
public:
    void help(int start, vector<int>& cookies, vector<int>& allotted, int k, int& res) {
        if(start == cookies.size()) {
            res = min(res, *max_element(allotted.begin(), allotted.end()));
            return;
        }
        for(int i=0; i<k; i++) {
            allotted[i] += cookies[start];
            help(start+1, cookies, allotted, k, res);
            allotted[i] -= cookies[start];
        }
    }
    int distributeCookies(vector<int>& cookies, int k) {
        int res = INT_MAX;
        vector<int> allotted(k, 0);
        help(0, cookies, allotted, k, res);
        return res;
    }
};