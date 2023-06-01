class Solution {
public:
    string help(unordered_set<string>& s, int n, string curr) {
        if(curr.size() == n) {
            if(!s.count(curr))
                return curr;
            else
                return "";
        }
        string temp = help(s, n, curr+"0");
        string temp1 = help(s, n, curr+"1");
        return temp == "" ? temp1 : temp;
    }
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<string> s(nums.begin(), nums.end());
        return help(s, nums.size(), "");
    }
};