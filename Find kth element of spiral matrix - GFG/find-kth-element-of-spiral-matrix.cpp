//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

// } Driver Code Ends
class Solution
{
    public:
    /*You are required to complete this method*/
    int findK(int a[MAX][MAX],int n,int m,int k)
    {
 		// Your code goes here.
 		 //vector<int>ans;
        // int n=v.size();
        // int m=v[0].size();
        int ct=0;
        
        int lf=0,rt=m-1;
        int tp=0,bt=n-1;
        while(lf<=rt&&tp<=bt){
            
        for(int i=lf;i<=rt;i++){
            
            ct++;
            if(ct==k) return  a[tp][i];
           

        }
        tp++;
        for(int i=tp;i<=bt;i++){
            
            ct++;
            if(ct==k) return  a[i][rt];
            

        }
        rt--;
        if(tp<=bt){
        for(int i=rt;i>=lf;i--){
            ct++;
            if(ct==k) return  a[bt][i];
            
            
        }
        bt--;
        }
        if(rt>=lf){
        for(int i=bt;i>=tp;i--){
            ct++;
            if(ct==k) return  a[i][lf];
            
            
        }
        lf++;
        }


        }
       
    }
};





//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n,m;
        int k=0;
        //cin>>k;
        cin>>n>>m>>k;
        int a[MAX][MAX];
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }
        Solution ob;
        cout<<ob.findK(a,n,m,k)<<endl;
        
       
    }
}
// } Driver Code Ends