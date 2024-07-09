class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        int n=s.size();
        if(s[0]==')'|| s[0]=='}' || s[0]==']') return false;
        for(int i=0;i<n;i++){
            if(s[i]=='('|| s[i]=='{'|| s[i]=='['){
                st.push(s[i]);
            }

            else{
                char a= s[i];
                if(a==')'&& st.size()!=0 && st.top()=='(') st.pop();
               else  if(a=='}'&& st.size()!=0 && st.top()=='{') st.pop();
                else if(a==']'&& st.size()!=0 && st.top()=='[') st.pop();
                else return false;
            }
        }

        return st.size()==0;
    }
};