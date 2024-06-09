class Solution {
public:


    void rec(int ind, int n,vector<int>&ds,vector<int>&nums ,vector<vector<int>>&ans){
        if(ind == n) {
            ans.push_back(ds);
            return ;
        }

        ds.push_back(nums[ind]);
        rec(ind+1, n,ds, nums, ans);
        ds.pop_back();
        rec(ind+1,n, ds, nums, ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> ds;
        vector<vector<int>>ans;
        int n=nums.size();
        rec(0,n,ds,nums, ans);
        return ans;
    }
};