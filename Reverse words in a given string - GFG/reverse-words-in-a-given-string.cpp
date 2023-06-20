//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to reverse words in a given string.
    
    
    void swap(string &s1,string &s2){
        string temp=s1;
        s1=s2;
        s2=temp;
    }
    
    
    
    string reverseWords(string s) 
    { 
        // code here 
        vector<string> v;
        
        string s1="";
        for(int i=0;i<s.size();i++){
            if(s[i]=='.'){
                v.push_back(s1);
                s1.clear();
            }
            else{
                s1.push_back(s[i]);
            }
        }
        v.push_back(s1);
        
        for(int i=0;i<v.size();i++){
            swap(v[i],v[v.size()-1-i]);
        }
        
        string ans="";
        
        for(int i=v.size()-1;i>=0;i--){
            ans=ans+v[i];
            ans=ans+".";
        }
        
        ans.pop_back();
        return ans;
    } 
};

//{ Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends