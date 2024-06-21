class Solution {
public:
void nextPermutation(vector<int>& nums) {
        int ind=-1;
        int n=nums.size();
        for(int i= n-1;i>=1;i--){

            if(nums[i]>nums[i-1]){
                
                ind=i;
                break;
            }
        }
        if(ind==-1){
            sort(nums.begin(),nums.end());
            return ;
        }



        //find smallest value greater than nums[ind]-1 from range ind+1 to n

        int index_greater=0;
        
        int greater_val=INT_MAX;
        for(int i=n-1;i>=ind;i--){
           if(nums[i]>nums[ind-1] && greater_val>nums[i]){
                greater_val=nums[i];
                index_greater=i;
                
           }
        }
        swap(nums[index_greater],nums[ind-1]);
        reverse(nums.begin()+ind,nums.end());
        return ;
    }
    string getPermutation(int n, int k) {
        string x="";
        for(int i=1;i<=n;i++){
        x+='0'+i;
    }

    vector<string>ans;
    
    do{
        ans.push_back(x);
    }while(next_permutation(x.begin(),x.end()));

    return ans[k-1];

        
    }
};