class Solution {
public:


    bool function(string &s, string &t){
       unordered_map<int,int>v;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(v.find(s[i]-'a')==v.end()){
                v[s[i]-'a']=t[i]-'a';
            }
            else if(v[s[i]-'a']!=t[i]-'a') return false;
        }
        return true;
    }
    bool isIsomorphic(string s, string t) {
        
        return function(s,t)&& function(t,s);
    }
};