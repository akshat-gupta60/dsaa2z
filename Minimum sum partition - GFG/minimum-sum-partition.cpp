//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
	int minDifference(int nums[], int n)  { 
	       
        long long sum=0;


        

      
       

       

        for(int i=0;i<n;i++){
            sum=sum+nums[i];
        }
        
        vector<vector<bool>> dp(n,vector<bool>(sum+1,0));

        for(int i=0;i<n;i++){
            dp[i][0]=true;
        }

       if(nums[0]>=0){
           if(nums[0]<=sum){
               dp[0][nums[0]]=true;
           }
       }

        


        for(int ind=1;ind<n;ind++){
            for(int j=1;j<=sum;j++){
                bool not_take=dp[ind-1][j];
                bool take=false;
                if(nums[ind]<=j){
                    take=dp[ind-1][j-nums[ind]];
                }

                dp[ind][j]=take||not_take;
            }
        }
        int mini=1e8;
        for(int i=0;i<=sum;i++){
            if(dp[n-1][i]==true){
                int sum1=i;
                int sum2=sum-i;
                mini=min(mini,abs(sum1-sum2));
            }
        }
         return mini;
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends