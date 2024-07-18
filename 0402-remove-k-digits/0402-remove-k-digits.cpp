class Solution {
public:
    string removeKdigits(string num, int k) {
        int n=num.size();

        stack<char> st;

        for(int i=0;i<n;i++){

            while(!st.empty() && st.top()>num[i] && k>0){
                k--;
                st.pop();
            }
            st.push(num[i]);
        }

        while(!st.empty() && k>0){
            st.pop();
            k--;
        }

        string ans="";
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        int n1=ans.size();
        for(int i=n1-1;i>=0;i--){
            if(ans[i]!='0') break;
            else ans.pop_back();
        }

        reverse(ans.begin(),ans.end());
        if(ans=="") return "0";
        return ans;
    }
};