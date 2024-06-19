class Solution {
public:

    bool check(string &ds, map<char,char>&m1, string &digit){
        string ch="";

        for(int i=0;i<ds.size();i++){
            ch=ch+(m1[ds[i]]);
        }
        // sort(ch.begin(),ch.end());

        return digit==ch;
    }
    void rec(int ind, string &s, string &ds,vector<string>&ans,string &digits,map<char,char>&m1){
        if(ind==s.size()){
            if(ds.size()==digits.size() && check(ds,m1,digits)==true){
                ans.push_back(ds);
            }
            return;
        }

        ds.push_back(s[ind]);
        rec(ind+1,s,ds,ans,digits,m1);
        ds.pop_back();
        rec(ind+1,s,ds,ans,digits,m1);
    }
    vector<string> letterCombinations(string digits) {


        if(digits.size()==0) return {};
        map<char,string>m;
        m['2']="abc",
        m['3']="def",
        m['4']="ghi",
        m['5']="jkl",
        m['6']="mno",
        m['7']="pqrs",
        m['8']="tuv",
        m['9']="wxyz";
        map<char,char>m1;
        m1['a']='2',m1['b']='2',m1['c']='2',
        m1['d']='3',m1['e']='3',m1['f']='3',
        m1['g']='4',m1['h']='4',m1['i']='4',
        m1['j']='5',m1['k']='5',m1['l']='5',
        m1['m']='6',m1['n']='6',m1['o']='6',
        m1['p']='7',m1['q']='7',m1['r']='7',m1['s']='7',
        m1['t']='8',m1['u']='8',m1['v']='8',
        m1['w']='9',m1['x']='9',m1['y']='9',m1['z']='9';


        string s="";
        for(int i=0;i<digits.size();i++){
            s=s+(m[digits[i]]);
        }
        string ds="";
        vector<string>ans;

        rec(0,s,ds,ans,digits,m1);
        set<string>st;
        for(int i=0;i<ans.size();i++){
            st.insert(ans[i]);
        }

        vector<string>ans1;
        for(auto pr:st){
            ans1.push_back(pr);
        }
        return ans1;



    }
};