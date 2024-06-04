class Solution {
public:


    int check(vector<int>& arr, int a){

        int n=arr.size();
        int res=-1;
        int start=0,end=n-1;
        while(start<=end){
            int mid=start+(end-start)/2;

            if(arr[mid]>=a){
                res=a;
                end=mid-1;
            }
            else start=mid+1;
        }

        
        return (a-res);


        
    }
    int findKthPositive(vector<int>& nums, int k) {
        
        int n=nums.size();
        int start=0,end=n-1;
        int res=-1;

        if(k<nums[0]) return k;
        if(k>=nums[n-1]) return n+k;
        while(start<=end){
            int mid=start+(end-start)/2;

            if(nums[mid]-mid-1>=k){
                res=mid;
                end=mid-1;
            }
           
            else{
                start=mid+1;
            }
        }

        if(res==-1) return nums[n-1]+k-(nums[n-1]-(n-1)-1);
        int ans=nums[res-1]+k-(nums[res-1]-(res-1)-1);
        return ans;
    }
};