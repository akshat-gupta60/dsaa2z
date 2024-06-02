class Solution {
public:


    bool check(vector<int>&nums, int mid, int thres){
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){

            

            if(nums[i]<mid){
                sum=sum+1;
            }


            else if(nums[i]%mid==0){
                sum=sum+(nums[i]/mid);
            }
            else{
                 sum=sum+(nums[i]/mid)+1;
            }
        }

        if(sum<=thres) return true;
        return false;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int start=1, end=1e6+2;

        int res=-1;
        while(start<=end){
            int mid=start+(end-start)/2;

            if(check(nums,mid,threshold)==true){
                res=mid;
                end=mid-1;
            }
            else start=mid+1;
        }
        return res;

    }
};