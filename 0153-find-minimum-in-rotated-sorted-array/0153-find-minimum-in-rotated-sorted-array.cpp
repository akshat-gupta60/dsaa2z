class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int n=nums.size();
        int start=0; int end=n-1;
        int ans=1e9;
        while(start<=end){
            int mid=start+(end-start)/2;
            //left part sorted
            if(nums[mid]>=nums[start]){
                ans=min(ans,nums[start]);
                start=mid+1;
            }
            //right part sorted 
            else if(nums[mid]<=nums[end]){
                ans=min(ans,nums[mid]);
                end=mid-1;
            }

            



            
            
        }
        return ans;
    }
};