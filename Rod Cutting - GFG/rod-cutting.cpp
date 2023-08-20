//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
  
    int rec(int ind ,int n,int price[],vector<vector<int>>&dp){
        
        if(ind==0){
            if(n>0){
                return price[0]*n;
            }
            return 0;
        }
        if(dp[ind][n]!=-1) return dp[ind][n];
        
        int not_take=0+rec(ind-1,n,price,dp);
        int take=-1e9;
        
        if(n>=ind+1){
            take=price[ind]+rec(ind,n-ind-1,price,dp);
        }
        
        return dp[ind][n]=max(take,not_take);
        
    }
    int cutRod(int price[], int n) {
        //code here
        
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        
        
        for(int i=0;i<=n;i++){
            if(i>0) dp[0][i]=price[0]*i;
            else dp[0][i]=0;
        }
        
        for(int ind=1;ind<n;ind++){
            for(int sum=0;sum<=n;sum++){
                int not_take=0+dp[ind-1][sum];
                int take=-1e9;
        
                if(sum>=ind+1){
                 take=price[ind]+dp[ind][sum-ind-1];
                     }
        
                dp[ind][sum]=max(take,not_take);
            }
        }
        return dp[n-1][n];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends