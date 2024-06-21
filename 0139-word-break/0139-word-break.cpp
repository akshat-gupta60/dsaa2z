class Solution {
public:

    bool rec( int ind, string &s, vector<string>&wordDict, vector<int>&dp){


        if(ind>=s.size()){
            return true;
        }

        if(dp[ind]!=-1){
            return dp[ind];
        }

        for(int i=0;i<wordDict.size();i++){
            if(s.substr(ind,wordDict[i].size())==wordDict[i]){
                if(rec(ind+wordDict[i].size(),s,wordDict,dp)==true){
                    return dp[ind]= true;
                }
            }
        }
        return dp[ind]=false;

    }
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int>dp(s.size()+1,-1);
       return  rec(0,s,wordDict,dp);
    }
};