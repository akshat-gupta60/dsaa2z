class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int k) {
     unordered_map<int,int>m;

        int n=nums.size();
        int ct=0;
        int pf_sum=0;
        for(int i=0;i<n;i++){
            pf_sum=pf_sum+nums[i];

            if(pf_sum==k) ct++;

            if(m.find(pf_sum-k)!=m.end()){
                ct=ct+m[pf_sum-k];
            }
             
            
                    m[pf_sum]++;
            
            
        }

        if(m.find(pf_sum-k)==m.end()){
            ct=ct+m[pf_sum-k];
        }

        return ct;
    }
};