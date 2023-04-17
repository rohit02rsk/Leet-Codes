class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int max_candies = *max_element(candies.begin(), candies.end());
        vector<bool> res;
        for(int i : candies) {
            if(i + extraCandies >= max_candies) res.push_back(true);
            else res.push_back(false);
        }
        return res;
    }
};