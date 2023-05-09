class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& v) {
        map<int,int>m1;
        map<int,int>m2;
        int n=v.size();
        vector<int>ans;
        for(int i=0;i<n;i++){
            m1[v[i]]++;
        }
        for(int i=0;i<n;i++){
            m2[v[i]]++;
            m1[v[i]]--;
        
            int a=0;int b=0;
            for(auto pr:m1){
                if(pr.second!=0)
                a++;
            }
             for(auto pr1:m2){
                  if(pr1.second!=0)
                b++;
            }
            ans.push_back(b-a);
            
        }
        return ans;
    }
};