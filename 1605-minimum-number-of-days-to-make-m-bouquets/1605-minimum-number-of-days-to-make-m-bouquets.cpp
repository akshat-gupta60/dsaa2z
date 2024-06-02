class Solution {
public:


    bool check(vector<int>&v, int mid, int m, int k  ){

        int ans=0;
        int ct=0;
        int n=v.size();
        for(int i=0;i<n;i++){

            
             if(v[i]>mid){
                ct=0;
                continue;
            }
            if(v[i]<=mid){
                ct=ct+1;
            }
            if(ct==k){
                
                ans=ans+1;
                ct=0;
                continue;
                
                

            }
           
        }

        if(ct==k) ans=ans+1;
        if(ans>=m) return true;
        return false;
    }
    int minDays(vector<int>& v, int m, int k) {
        int start=0; int end=1e9;
        int res=-1;
        while(start<=end){

            int mid=start+(end-start)/2;

            if(check(v,mid,m,k)==true){
                res=mid;
                end=mid-1;
            }
            else{
                start=mid+1;
            }

        }
        return res;
    }
};