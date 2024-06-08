class Solution {
public:
    string largestOddNumber(string num) {
        string ans="";
        int n=num.size();
        int ind=-1;
        for(int i=n-1;i>=0;i--){
            if((num[i]-'0')%2!=0){
                ind=i;break;
            }
        }

        if(ind==-1) return "";

        for(int i=0;i<=ind;i++){
            ans.push_back(num[i]);
        }
        return ans;
    }
};