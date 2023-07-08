class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        if(n == 1 or n == k) return 0;
        long long mx = 0;
        long long mn = 0;
        vector<int> arr;
        
        for(int i=0; i<n-1; i++) arr.push_back(weights[i] + weights[i+1]);
        sort(arr.begin(), arr.end());
        for(int i=0; i<k-1; i++) {
            mn += arr[i];
            mx += arr[n-i-2];
        }
        return mx - mn;
    }
};