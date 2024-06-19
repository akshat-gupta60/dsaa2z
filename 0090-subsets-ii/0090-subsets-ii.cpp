class Solution {
public:


    void rec(int ind, vector<int>&nums, int n,vector<int>&ds, vector<vector<int>>&ans){

     
            ans.push_back(ds);
       
        

        for(int i=ind;i<n;i++){
            if(i!=ind&& nums[i]==nums[i-1]) continue;
            ds.push_back(nums[i]);
            rec(i+1,nums,n,ds,ans);
            ds.pop_back();

        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>ds;
        vector<vector<int>>ans;
        int n=nums.size();
        rec(0,nums,n,ds,ans);
        return ans;


    }
};