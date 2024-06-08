class Solution {
public:
    string removeOuterParentheses(string s) {
        int n=s.size();
        vector<int>v(n,0);
        v[0]=1;
        int sum=0;
        for(int i=0;i<n;i++){
            
            
            if(s[i]=='('){
                sum++;
            }
             if(s[i]==')'){
                sum--;
            }
             if(sum==0){
                v[i]=1;
                if(i+1<n){
                    v[i+1]=1;
                }
            }
           
        }

        if(sum==0) v[n-1]=1;

        string ans="";
        for(int i=0;i<n;i++){
            if(v[i]==0){
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};