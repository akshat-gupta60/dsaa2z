//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:

    bool rec(int ind,int sum,vector<int>&arr,vector<vector<int>>&dp){
        if(sum==0) return true;
        if(ind==0) return (arr[0]==sum);
        if(dp[ind][sum]!=-1) return dp[ind][sum];
        
       
        int take =false;
        if(arr[ind]<=sum) take=rec(ind-1,sum-arr[ind],arr,dp);
        int not_take=rec(ind-1,sum,arr,dp);
        return dp[ind][sum]= take||not_take;
    }
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n=arr.size();
        
        vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
        return rec(n-1,sum,arr,dp);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends