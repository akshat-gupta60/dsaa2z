class Solution {
public:



    bool check(string &s){

        int n=s.size();
        int ct=0;

        for(int i=0;i<n;i++){

            if(s[i]==')') ct=ct-1;
            if(s[i]=='(') ct=ct+1;
            if(ct<0) return false;
        }

        if(ct==0) return true;
        return false;
    }
    void rec(int ind,int n, string &ds, vector<string>&ans){

        if(ind==n){
            if(check(ds)==true && ds!=""){
                ans.push_back(ds);
               
            }
             return ;
        }

        ds.push_back('(');
        rec(ind+1,n, ds, ans);
        ds.pop_back();
        ds.push_back(')');
        rec(ind+1,n,ds, ans);
        ds.pop_back();

    }
    vector<string> generateParenthesis(int n) {
        string ds="";
        vector<string>ans;

        rec(0,2*n,ds,ans);
        return ans;
    }
};