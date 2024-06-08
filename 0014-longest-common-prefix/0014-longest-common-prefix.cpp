class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int sz=1e9;
        string str_of_min_size="";

        int n=strs.size();
        for(int i=0;i<n;i++){
            if(strs[i].size()<sz){
                sz=strs[i].size();
                str_of_min_size=strs[i];
            }
        }
        string ans="";
        for(int i=0;i<str_of_min_size.size();i++){
            char a=str_of_min_size[i];
            for(int j=0;j<n;j++){
                if(a!=strs[j][i]){
                    return ans;
                }
            }
            ans.push_back(a);
        }
        return ans;
    }
};