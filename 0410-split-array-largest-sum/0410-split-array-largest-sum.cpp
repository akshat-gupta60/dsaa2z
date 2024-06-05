class Solution {
public:



    bool check(vector<int>&nums, int mid, int k){
        int n=nums.size();
        int sum=0;
        int ct=0;
        for(int i=0;i<n;i++){
            sum=sum+nums[i];

            if(sum>mid){
                ct=ct+1;
                sum=nums[i];
            }

        }
        if(sum!=0) ct=ct+1;

        if(ct<=k) return true;
        return false;
    }
    int splitArray(vector<int>& nums, int k) {
        int start=0, end= 1e9;
        int res=-1;

        for(int i=0;i<nums.size();i++){
            start=max(start,nums[i]);
        }


        while(start<=end){
            int mid= start+(end-start)/2;

            if(check(nums, mid, k)==true){
                res=mid;
                end=mid-1;
            }
            else start=mid+1;
        }
        return res;
    }
};