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
        
        vector<int>prev(n+1,0),curr(n+1,0);
        
        
        for(int i=0;i<=n;i++){
            if(i>0) prev[i]=price[0]*i;
            else prev[i]=0;
        }
        
        for(int ind=1;ind<n;ind++){
            for(int sum=0;sum<=n;sum++){
                int not_take=0+prev[sum];
                int take=-1e9;
        
                if(sum>=ind+1){
                 take=price[ind]+curr[sum-ind-1];
                     }
        
                curr[sum]=max(take,not_take);
            }
            prev=curr;
        }
        return prev[n];
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