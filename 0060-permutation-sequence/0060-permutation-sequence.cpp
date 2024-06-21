class Solution {
public:
string nextPermutation(string &nums) {
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
            return nums;
        }



        //find smallest value greater than nums[ind]-1 from range ind+1 to n

        int index_greater=0;
        
        int greater_val=INT_MAX;
        for(int i=n-1;i>=ind;i--){
            int a=nums[i]-'0';
            int b=nums[ind-1]-'0';
           if(a>b && greater_val>a){
                greater_val=a;
                index_greater=i;
                
           }
        }
        swap(nums[index_greater],nums[ind-1]);
        reverse(nums.begin()+ind,nums.end());
        return nums;
    }
    string getPermutation(int n, int k) {
        string x="";
        for(int i=1;i<=n;i++){
        x+='0'+i;
    }

   
    int a=k;
    string ans=x;
    while(a>1){
       
        ans=(nextPermutation(x));
        a--;
       
        
    }
    return ans;

        
    }
};