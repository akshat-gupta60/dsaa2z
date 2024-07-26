class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i=0,j=0;
        int n=nums.size();
        int ct0=0;
        int ans=0;

        while(j<n){

            if(nums[j]==0){
                ct0++;
            }

            if(ct0<=k){
                ans=max(ans,j-i+1);
                j++;
            }
            else if(ct0>k){

                while(ct0>k){
                    if(nums[i]==0) ct0--;
                    i++;
                }
                if(ct0<=k){
                    ans=max(ans,j-i+1);
                }
                j++;
            }
        }

        return ans;
    }
};