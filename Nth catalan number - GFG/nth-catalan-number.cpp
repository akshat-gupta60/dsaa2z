//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the nth catalan number.
    const int mod = 1e9 + 7;

int rec(int n, vector<int>& dp) {
    if (n == 0) {
        return 1;
    }

    if (dp[n] != -1) {
        return dp[n];
    }

    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum = (sum + (rec(i, dp) * 1LL * rec(n - 1 - i, dp)) % mod) % mod;
    }

    return dp[n] = sum;
}

int findCatalan(int n) {
    vector<int> dp(n + 1, -1);
    return rec(n, dp);
}
};

//{ Driver Code Starts.
int main() 
{
	int t;
	cin>>t;
	while(t--) {
	    
	    int n;
	    cin>>n;
	    Solution obj;
	    cout<< obj.findCatalan(n) <<"\n";    
	}
	return 0;
}
// } Driver Code Ends