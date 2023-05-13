//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
    int bitMagic(int n, vector<int> &arr) {
        // code here
        int ct=0;
        int z=0,o=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]!=arr[arr.size()-i-1]){
                if(arr[i]==0&&arr[arr.size()-1]==1)
                z++;
                o++;
                if(arr[i]==1&&arr[arr.size()-1]==0)
                z++;
                o++;
                
            }
        }
        
        if(z>=o){
            ct=ct+(o/2);
            if(o%2!=0){
                ct++;
            }
        }
        else  if(o>z){
            ct=ct+(z/2);
            if(z%2!=0){
                ct++;
            }
        }
        return ct;
        
        
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n;
        scanf("%d",&n);
        
        
        vector<int> arr(n);
        Array::input(arr,n);
        
        Solution obj;
        int res = obj.bitMagic(n, arr);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends