class Solution {
public:
    int trap(vector<int>& v) {
        vector<int>mxl,mxr;
        int n=v.size();
        mxl.push_back(v[0]);
        mxr.push_back(v[n-1]);

        for(int i=1;i<n;i++){
            int a=max(mxl[mxl.size()-1],v[i]);
            mxl.push_back(a);
        }

        for(int i=n-2;i>=0;i--){
            int a=max(mxr[mxr.size()-1],v[i]);
            mxr.push_back(a);
        }
        reverse(mxr.begin(),mxr.end());

        int ans=0;
        for(int i=0;i<n;i++){
            ans=ans+ min(mxl[i],mxr[i])-v[i];
        }

        return ans;


    }
};