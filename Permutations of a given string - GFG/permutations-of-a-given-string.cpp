//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	
	
	    void rec(int ind,string &S,set<string>&ans){
	        if(ind==S.size()){
	            ans.insert(S);
	        }
	        
	        for(int i=ind;i<S.size();i++){
	            swap(S[ind],S[i]);
	            rec(ind+1,S,ans);
	            swap(S[ind],S[i]);
	        }
	        
	        
	        
	    }
		vector<string>find_permutation(string S)
		{
		    // Code here there
		    vector<string>ans1;
		    set<string>ans;
		    rec(0,S,ans);
		    for(auto it :ans){
		        ans1.push_back(it);
		    }
		    
		   
		    return ans1;
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends