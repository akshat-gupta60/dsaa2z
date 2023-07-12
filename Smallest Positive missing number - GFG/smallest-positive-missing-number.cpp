//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to find the smallest positive number missing from the array.
    int missingNumber(int arr[], int n) 
    { 
        // Your code here
        for(int i=0;i<n;i++){
            if(arr[i]<0) arr[i]=0;
        }
        
        for(int i=0;i<n;i++){
            if(0<=abs(arr[i])-1&&abs(arr[i])<n){
                if(arr[abs(arr[i])-1]>0){
                    arr[abs(arr[i])-1]=-arr[abs(arr[i])-1];
                }
                else if(arr[abs(arr[i])-1]==0){
                     arr[abs(arr[i])-1]=-(n+3);
                }
            }
        }
        for(int i=1;i<=n;i++){
            if(arr[i-1]>=0){
                return i;
            }
        }
        return n+1;
        
        
    } 
};

//{ Driver Code Starts.

int missingNumber(int arr[], int n);

int main() { 
    
    //taking testcases
    int t;
    cin>>t;
    while(t--){
        
        //input number n
        int n;
        cin>>n;
        int arr[n];
        
        //adding elements to the array
        for(int i=0; i<n; i++)cin>>arr[i];
        
        Solution ob;
        //calling missingNumber()
        cout<<ob.missingNumber(arr, n)<<endl;
    }
    return 0; 
} 
// } Driver Code Ends