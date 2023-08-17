//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    
    int rec(int ind,int w,int wt[],int val[],vector<vector<int>>&dp){
        if(ind==0){
            if(w>=wt[0]){
                return val[0];
            }
            else return 0;
        }
        if(wt==0) return 0;
        if(wt<0) return 0;
        
        if(dp[ind][w]!=-1) return dp[ind][w];
        
        int not_pick=0+rec(ind-1,w,wt,val,dp);
        
        int pick=-1e8;
        if(wt[ind]<=w){
            pick=val[ind]+rec(ind-1,w-wt[ind],wt,val,dp);
        }
        
        return dp[ind][w]=max(pick,not_pick);
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<vector<int>>dp(n+1,vector<int>(W+1,-1));
       return rec(n-1,W,wt,val,dp);
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends