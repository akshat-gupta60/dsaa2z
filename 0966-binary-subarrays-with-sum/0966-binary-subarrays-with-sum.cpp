class Solution {
public:

    int func(vector<int>&nums, int goal){
        if(goal<0) return 0;
          int n=nums.size();

        int i=0,j=0;

        int sum=0;
        int ct=0;

        while(j<n){
            sum=sum+nums[j];

            if(sum<=goal){
                ct=ct+j-i+1;
                j++;
            }
            else if(sum>goal){
                while(sum>goal){
                    sum=sum-nums[i];
                    i++;
                }
                if(sum<=goal){
                    ct=ct+j-i+1;
                }
                j++;
            }
        }
        return ct;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {

        int a= func(nums,goal);
        int b=func(nums, goal-1);
        return a-b;
        
      

    }
};