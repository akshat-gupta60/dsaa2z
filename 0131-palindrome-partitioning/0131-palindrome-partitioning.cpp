class Solution {
public:


    bool check_pal(string &st){

        int n=st.size();

        for(int i=0,j=n-1;i<j;i++,j--){
            if(st[i]!=st[j]) return false;
        }
        return true;
    }
    void rec(int ind, string &s, vector<string>&ds, vector<vector<string>>&ans){

        if(ind==s.size()){
            ans.push_back(ds);
            return ;
        }

        for(int i=ind; i<s.size(); i++){
            string st= s.substr(ind,i-ind+1);
            if(check_pal(st)){
                ds.push_back(st);
                rec(i+1,s,ds,ans);
                ds.pop_back();
            }

        }
    }

    vector<vector<string>> partition(string s) {
        vector<string>ds;

        vector<vector<string>>ans;
        rec(0,s,ds,ans);
        return ans;


    }
};