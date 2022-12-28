class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        make_heap(piles.begin(), piles.end());
        while (k > 0) {
            pop_heap(piles.begin(), piles.end());
            piles.back() -= piles.back() / 2;
            push_heap(piles.begin(), piles.end());
            k--;
        }
        return accumulate(piles.begin(), piles.end(), 0);
    }
};