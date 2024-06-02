class Solution {
public:


   long long int check(vector<int>&piles, int k){
        long long int ct=0;
        int n=piles.size();
        for(int i=0;i<n;i++){
            if(piles[i]<k){
                ct++;
            }
            else{
                ct=ct+(piles[i]/k);
                if(piles[i]%k!=0) ct=ct+1;
            }
        }
        return ct;

    }

   
    int minEatingSpeed(vector<int>& piles, int h) {
        long long start=1, end=1e9;
        long long res=-1;
        while(start<=end){
            int mid=start+(end-start)/2;

            if(check(piles,mid)<=h){
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