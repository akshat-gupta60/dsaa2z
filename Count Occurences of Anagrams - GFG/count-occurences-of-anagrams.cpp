//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	//User function template for C++

	int search(string pat, string txt) {
	    // code here
	    map<char,int>m1;
	    int n=txt.size();
	    for(int i1=0;i1<pat.size();i1++){
	        m1[pat[i1]]++;
	    }
	    
	    int i=0;int j=0;
	    int ct=m1.size();
	    int ans=0;
	    while(j<txt.size()){
	        if(m1.find(txt[j])!=m1.end()){
	            m1[txt[j]]--;
	            if(m1[txt[j]]==0) ct--;
	        }
	        
	        if(j-i+1<pat.size()){
	            j++;
	        }
	        else if(j-i+1==pat.size()){
	            if(ct==0) ans++;
	            
	            if(m1.find(txt[i])!=m1.end()){
	                m1[txt[i]]++;
	                
	                if(m1[txt[i]]==1) ct++;
	            }
	            i++;j++;
	        }
	    }
	    return ans;
	       
	}



};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends