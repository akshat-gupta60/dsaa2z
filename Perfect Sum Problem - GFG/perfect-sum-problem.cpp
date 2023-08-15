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
        vector<vector<int>>dp(n1+1,vector<int>(sum+1,-1));
        for(int i=0;i<n;i++){
            if(arr[i]==0) ct++;
        }
        
        return pow(2,ct)*rec(n1-1,v,sum,dp);
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