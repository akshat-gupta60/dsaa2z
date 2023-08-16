//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the nth catalan number.
    int mod=1e9+7;
    
    
    int rec(int n,vector<int>&dp){
        if(n==1||n==0) {
            return 1;
        }
        
        if(dp[n]!=-1) return dp[n]%mod;
        
        int sum=0;
        for(int i=0;i<n;i++){
            int a=rec(i,dp)%mod;
            int b=rec(n-1-i,dp)%mod;
            
           sum=(sum+((a*b)%mod))%mod;
        }
        return dp[n]=sum%mod;
    }
    int findCatalan(int n) 
    {
        //code here
       vector<int> dp(n + 1, 0);
    dp[0] = dp[1] = 1;

    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            dp[i] = (dp[i] + (dp[j] * 1LL * dp[i - 1 - j]) % mod) % mod;
        }
    }

    return dp[n];
        
        
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