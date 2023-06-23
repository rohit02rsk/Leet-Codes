class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int res = high;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            long long int temp = 0;
            for(int i=0; i<piles.size(); i++) temp += 1LL*ceil((double) piles[i] / mid);
            if(temp > h) {
                low = mid + 1;
            } else {
                res = min(res, mid);
                high = mid - 1;
            }
        }
        return res;
    }
};