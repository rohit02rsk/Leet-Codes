class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> res;
        unordered_set<int> s1(nums1.begin(), nums1.end());
        unordered_set<int> s2(nums2.begin(), nums2.end());
        
        vector<int> temp;
        for(auto x: s1) {
            if(!s2.count(x)) 
                temp.push_back(x);
        }
        res.push_back(temp);
        temp.clear();
        
        for(auto x: s2) {
            if(!s1.count(x)) 
                temp.push_back(x);
        }
        res.push_back(temp);

        return res;
    }
};