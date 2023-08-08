//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    
    int rec(int ind,int arr[],vector<int>&dp){
        if(ind==0) return arr[0];
        
        if(ind<0) return 0;
        
        if(dp[ind]!=-1) return dp[ind];
        
        int pick=arr[ind]+rec(ind-2,arr,dp);
        int notpick=0+rec(ind-1,arr,dp);
        
        return dp[ind]= max(pick,notpick);
        
        
        
    }
    int FindMaxSum(int arr[], int n)
    {
        // Your code here
        vector<int>dp(n+1,-1);
        
        dp[0]=arr[0];
        
        for(int i=1;i<n;i++){
            
            
            int pick=arr[i];
            if(i>1) pick=pick+dp[i-2];
            int notpick=0+dp[i-1];
            dp[i]=max(pick,notpick);
        }
        return dp[n-1];
       
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
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}

// } Driver Code Ends