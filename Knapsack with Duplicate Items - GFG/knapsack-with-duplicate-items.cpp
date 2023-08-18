//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    int rec(int ind ,int target,int val[],int wt[],vector<vector<int>>&dp){
        if(ind ==0){
             return val[0]*(target/wt[0]);
            
        }
        if(dp[ind][target]!=-1) return dp[ind][target];
        
        
        int not_take=0+rec(ind-1,target,val,wt,dp);
        int take=0;
        if(wt[ind]<=target){
            take=val[ind]+rec(ind,target-wt[ind],val,wt,dp);
        }
        
        return dp[ind][target]=max(take,not_take);
    }
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        
        vector<vector<int>>dp(N+1,vector<int>(W+1,0));
        
        for(int i=0;i<=W;i++){
            dp[0][i]=val[0]*(i/wt[0]);
        }
        
        
        for(int ind=1;ind<N;ind++){
            for(int target=0;target<=W;target++){
                int not_take=0+dp[ind-1][target];
                int take=0;
                if(wt[ind]<=target){
                    take=val[ind]+dp[ind][target-wt[ind]];
                }
        
         dp[ind][target]=max(take,not_take);
            }
        }
        
        return dp[N-1][W];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends