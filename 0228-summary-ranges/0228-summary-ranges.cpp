class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if(nums.size() == 0) 
            return {};
        string st = "";
        string end = "";
        vector<string> res;
        
        st = to_string(nums[0]);
        for(int i=1; i<nums.size(); i++) {
            if(nums[i] == nums[i-1] + 1) {
                end = to_string(nums[i]);
            }
            else {
                if(end == "") {
                    res.emplace_back(st);
                }
                else {
                    string temp = st + "->" + end;
                    res.emplace_back(temp);
                }
                st = to_string(nums[i]);
                end = "";
            }
        }
        if(end == "") {
            res.emplace_back(st);
        }
        else {
            string temp = st + "->" + end;
            res.emplace_back(temp);
        }

        return res;
    }
};