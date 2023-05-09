
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& v) {
        vector<int>ans;
        int n=v.size();
        int m=v[0].size();

        int lf=0,rt=m-1;
        int tp=0,bt=n-1;
        while(lf<=rt&&tp<=bt){
        for(int i=lf;i<=rt;i++){
            ans.push_back(v[tp][i]);

        }
        tp++;
        for(int i=tp;i<=bt;i++){
            ans.push_back(v[i][rt]);

        }
        rt--;
        if(tp<=bt){
        for(int i=rt;i>=lf;i--){
            ans.push_back(v[bt][i]);
        }
        bt--;
        }
        if(rt>=lf){
        for(int i=bt;i>=tp;i--){
            ans.push_back(v[i][lf]);
        }
        lf++;
        }


        }
        return ans;
    }
};