//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to count number of ways to reach the nth stair.
    vector<int> dp;
    int MOD = 1e9 + 7;
    int helper(int n) {
        if (n < 0) return 0;
        if (dp[n] != -1) return dp[n] % MOD;
        return dp[n] = ((helper(n-1) % MOD) + (helper(n-2) % MOD) % MOD);
    }
    int countWays(int n)
    {
        // your code here
        dp.resize(n+1,-1);
        if (n == 1) return 1;
        dp[0] = 1;
        dp[1] = 1;
        return helper(n) % MOD;
    }
};



//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking stair count
        int m;
        cin>>m;
        Solution ob;
        cout<<ob.countWays(m)<<endl; // Print the output from our pre computed array
    }
    return 0;
}

// } Driver Code Ends