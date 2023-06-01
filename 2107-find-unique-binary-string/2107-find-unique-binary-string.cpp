class Solution {
public:
    string res = "";
    void help(unordered_set<string>& s, int n, string curr) {
        if(curr.size() == n) {
            if(!s.count(curr)) {
                res = curr;
                return;
            }
            else return;
        }
        help(s, n, curr+"0");
        help(s, n, curr+"1");
    }
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<string> s(nums.begin(), nums.end());
        help(s, nums.size(), "");
        return res;
    }
};