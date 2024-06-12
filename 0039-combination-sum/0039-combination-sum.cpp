class Solution {
public:


    void rec(int ind, vector<int>&v, vector<int>&ds, vector<vector<int>>&ans,int s, int sum){
         if(s>sum) return ;
        if(ind==v.size()){

            if(s==sum){
                ans.push_back(ds);
                
            }
            return ;
        }

        //pick
        ds.push_back(v[ind]);
        rec(ind, v,ds,ans,s+v[ind],sum);
        //not_pick
        ds.pop_back();
        rec(ind+1, v, ds, ans, s, sum);
      
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>ds;
        vector<vector<int>>ans;
        int s=0;
        rec(0,candidates,ds,ans,s,target);
        return ans;

    }
};