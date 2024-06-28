class Solution {
public:
    int minimumArea(vector<vector<int>>& v) {

        int n=v.size();
        int r1=n-1,r2=0,c1=v[0].size(),c2=0;

        for(int i=0;i<n;i++){
            for(int j =0;j<v[0].size();j++){
                if(v[i][j]==1){
                    r1=min(r1,i);
                    r2=max(r2,i);
                    c1=min(c1,j);
                    c2=max(c2,j);
                }
            }
        }

        return (r2-r1+1)*(c2-c1+1);
    }
};