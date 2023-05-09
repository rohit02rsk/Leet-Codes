class Solution {
public:
    bool eatBananas(vector<int> vec, int rate, int h) {
        long int hours = 0;
        for(int i : vec) {
            if(h < 0) return false;
            hours += ceil((double)i/rate);
        }
        if(hours > h) return false;
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());
        int res = r;
        
        while(l <= r) {
            int k = l+(r-l)/2;
            if(eatBananas(piles, k, h)) {
                res = min(res, k);
                r = k-1;  
            } else {
                l = k+1;
            }
        }
        
        return res;
    }
};