//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    void sort012(int a[], int n)
    {
        // code here 
        vector<int> arr(3, 0);
        for(int i=0; i<n; i++) arr[a[i]]++;
        for(int i=0; i<n; i++) {
            if(arr[0]) {
                a[i] = 0;
                arr[0]--;
            }
            else if(arr[1]) {
                a[i] = 1;
                arr[1]--;
            }
            else a[i] = 2;
        }
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }
    return 0;
}


// } Driver Code Ends