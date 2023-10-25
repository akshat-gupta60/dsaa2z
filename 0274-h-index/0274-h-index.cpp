class Solution {
public:
    int hIndex(vector<int>& v) {
        sort(v.begin(),v.end());
        int start=0;
        int end=v[v.size()-1];
        int res=0;
        int n=v.size();
        if(n==1&&v[0]!=0) return 1;
        if(n==1) return 0;
        while(start<=end){
            int mid=start+(end-start)/2;
            int ct=0;
            for(int i=0;i<n;i++){
                if(v[i]>=mid) ct++;
            }
            if(ct>=mid){
                res=mid;
                start=mid+1;
            }
            else if(ct<mid){
                end=mid-1;
            }
           

        }
        return res;
    }
};