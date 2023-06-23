//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int countOfSubstrings(string s, int k) {
        // code here
        map<char,int>m;
        int ans=0;
        int n=s.size();
        for(int i=0;i<k;i++){
            m[s[i]]++;
        }
        int fl=0;
        for(auto pr:m){
            if(pr.second!=0){
                fl++;
            }
        }
        if(fl==k-1) ans++;
        
        
        for(int i=k;i<n;i++){
            m[s[i]]++;
            m[s[i-k]]--;
             int fl1=0;
        for(auto pr:m){
            if(pr.second!=0){
                fl1++;
            }
        }
        if(fl1==k-1) ans++;
            
            
        }
        return ans;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        int K;
        cin>>S;
        cin>>K;

        Solution ob;
        cout << ob.countOfSubstrings(S,K) << endl;
    }
    return 0;
}
// } Driver Code Ends