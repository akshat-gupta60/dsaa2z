class Solution {
public:
    int largestRectangleArea(vector<int>& v) {
        int n=v.size();
        stack<pair<int,int>>st_left,st_right;

        vector<int>nsil,nsir;


        for(int i=0;i<n;i++){
            if(st_left.size()==0){
                nsil.push_back(-1);
            }
            else if(st_left.size()>0 && st_left.top().first<v[i]){
                nsil.push_back(st_left.top().second);
            }
            else if(st_left.size()>0 && st_left.top().first>=v[i]){
                while(st_left.size()>0 && st_left.top().first>=v[i]){
                    st_left.pop();
                }
                if(st_left.size()==0){
                    nsil.push_back(-1);
                }
                else if(st_left.top().first<v[i]){
                    nsil.push_back(st_left.top().second);
                }
            }
            st_left.push({v[i],i});
        }
        for(int i=n-1;i>=0;i--){
            if(st_right.size()==0){
                nsir.push_back(n);
            }
            else if(st_right.size()>0 && st_right.top().first<v[i]){
                nsir.push_back(st_right.top().second);
            }
            else if(st_right.size()>0 && st_right.top().first>=v[i]){
                while(st_right.size()>0 && st_right.top().first>=v[i]){
                    st_right.pop();
                }
                if(st_right.size()==0){
                    nsir.push_back(n);
                }
                else if(st_right.top().first<v[i]){
                    nsir.push_back(st_right.top().second);
                }
            }
            st_right.push({v[i],i});
        }

        reverse(nsir.begin(),nsir.end());
        int ans=0;
        for(int i=0;i<n;i++){
            int a=v[i]*(nsir[i]-nsil[i]-1);
            ans=max(ans,a);
        }
        return ans;

    }
};