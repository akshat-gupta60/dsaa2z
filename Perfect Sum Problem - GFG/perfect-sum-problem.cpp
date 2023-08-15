//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	
	int mod=1e9+7;
	
	int rec(int ind,vector<int>&arr,int sum,vector<vector<int>>&dp){
	    if(sum==0) return 1;
	    if(ind==0) return (arr[0]==sum);
	    
	    if(dp[ind][sum]!=-1) return dp[ind][sum];
	    int not_pick=rec(ind-1,arr,sum,dp);
	    int pick=0;
	    
	    if(arr[ind]<=sum){
	     pick=rec(ind-1,arr,sum-arr[ind],dp);
	    }
	    
	    return dp[ind][sum]=(pick+not_pick)%mod;
	    
	}
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        int ct=0;
        vector<int>v;
        for(int i=0;i<n;i++){
            if(arr[i]!=0) v.push_back(arr[i]);
        }
        int n1=v.size();
        vector<int>prev(sum+1,0);
        vector<int>curr(sum+1,0);
        
        
        for(int i=0;i<n;i++){
            if(arr[i]==0) ct++;
        }
        
        for(int i=0;i<n1;i++){
            prev[0]=1;
        }
        
        if(v[0]<=sum) prev[v[0]]=1;
        
        
        for(int ind=1;ind<n1;ind++){
            for(int j=0;j<=sum;j++){
                int not_pick=prev[j];
	    int pick=0;
	    
	    if(v[ind]<=j){
	     pick=prev[j-v[ind]];
	    }
	    curr[j]=(pick+not_pick)%mod;
            }
            prev=curr;
            
            
            
        }
        
        
        
        return pow(2,ct)*prev[sum];
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends