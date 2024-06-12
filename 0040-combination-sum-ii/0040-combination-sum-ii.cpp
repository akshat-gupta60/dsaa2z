class Solution {
public:


    void rec(int ind, vector<int>&v, vector<int>&ds, vector<vector<int>>&ans,int s, int sum){
         

         if(s>sum) return;
          if(s==sum){
                
                ans.push_back(ds);
                  return ;
                
            }
          
        if(ind==v.size()){
            return;
           
        }

        for(int i=ind;i<v.size();i++){
            if(i>ind && v[i]==v[i-1]) continue;
            
            
                  //pick
        ds.push_back(v[i]);
        rec(i+1, v,ds,ans,s+v[i],sum);
        //not_pick
        ds.pop_back();
            
        }

      
      
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int>ds;
       vector<vector<int>>ans;
       sort(candidates.begin(), candidates.end());
        int s=0;
        rec(0,candidates,ds,ans,s,target);
       
       
        return ans;
    }
};