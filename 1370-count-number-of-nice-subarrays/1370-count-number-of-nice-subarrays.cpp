class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        vector<int>odd;
        int n=nums.size();

        for(int i=0;i<n;i++){
            if(nums[i]%2!=0){
                odd.push_back(i);
            }
        }
        int i=0,j=k-1;
        int ans=0;
        
        while(j<odd.size()){
            int sx=1;
              if (i == 0) {
                sx *= (odd[i] + 1);  // Number of subarrays starting before the first odd
            } else {
                sx *= (odd[i] - odd[i - 1]);  // Number of subarrays starting after the previous odd
            }

            if (j == odd.size() - 1) {
                sx *= (n - odd[j]);  // Number of subarrays ending after the last odd
            } else {
                sx *= (odd[j + 1] - odd[j]);  // Number of subarrays ending before the next odd
            }
            ans=ans+sx;
            i++;j++;
        }
        
      
        

        return ans;


    }
};