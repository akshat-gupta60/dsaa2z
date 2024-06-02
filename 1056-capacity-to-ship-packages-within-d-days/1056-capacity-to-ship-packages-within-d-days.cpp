class Solution {
public:


    bool check(vector<int>&v, int mid, int days){

        int n=v.size();

        int ans=0;
        int sum=0;

        for(int i=0;i<n;i++){

            if(v[i]>mid) return false;
            sum=sum+v[i];

            if(sum>mid){
                sum=v[i];
                ans=ans+1;
            }
            
        }

        if(sum<mid){
            ans=ans+1;
        }
        
        
        return (ans<=days)?true:false;
    }
    int shipWithinDays(vector<int>& v, int days) {
        int start=1, end=1e9;
        int res=-1;
        while(start<=end){
            int mid=start+(end-start)/2;

            if(check(v,mid,days)==true){
                res=mid;
                end=mid-1;

            }
            else start=mid+1;
        }
        return res;
    }
};