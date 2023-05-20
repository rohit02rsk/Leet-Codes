class Solution {
public:
    int numTrees(int n) {
        vector<int> arr(n+1, 1);
        
        for(int i=2; i<=n; i++) {
            long long total = 0;
            for(int j=1; j<=i; j++) {
                total += arr[j-1] * arr[i-j];
            }
            arr[i]  = total;
        }
        
        return arr[n];
    }
};