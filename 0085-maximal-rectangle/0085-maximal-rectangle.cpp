class Solution {
public:
    int maximalRectangle(vector<vector<char>>& v) {
        int n=v.size();
        int m=v[0].size();

        vector<vector<int>>v1(n,vector<int>(m,0));

        for(int i=0;i<m;i++){
            v1[0][i]=v[0][i]-'0';
        }


        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++ ){

                if(v[i][j]=='0'){
                    v1[i][j]=0;
                }

                else{
                    v1[i][j]=v1[i-1][j]+1;
                }
            }
        }
        int ans=0;


        for(int i=0;i<n;i++){
            stack<pair<int,int>>st_left,st_right;
            vector<int>vec=v1[i];
            vector<int>left_sm,right_sm;

            for(int j=0;j<m;j++){
                if(st_left.size()==0){
                    left_sm.push_back(-1);
                }
                else if(st_left.size()>0 && st_left.top().first<vec[j]){
                    left_sm.push_back(st_left.top().second);
                }
                else if(st_left.size()>0 && st_left.top().first>=vec[j]){
                    while(st_left.size()>0 && st_left.top().first>=vec[j]){
                        st_left.pop();
                    }
                    if(st_left.size()==0){
                        left_sm.push_back(-1);
                    }
                    else if(st_left.top().first<vec[j]){
                        left_sm.push_back(st_left.top().second);
                    }
                }
                st_left.push({vec[j],j});
            }
            for(int j=m-1;j>=0;j--){
                if(st_right.size()==0){
                    right_sm.push_back(m);
                }
                else if(st_right.size()>0 && st_right.top().first<vec[j]){
                    right_sm.push_back(st_right.top().second);
                }
                else if(st_right.size()>0 && st_right.top().first>=vec[j]){
                    while(st_right.size()>0 && st_right.top().first>=vec[j]){
                        st_right.pop();
                    }
                    if(st_right.size()==0){
                        right_sm.push_back(m);
                    }
                    else if(st_right.top().first<vec[j]){
                        right_sm.push_back(st_right.top().second);
                    }
                }
                st_right.push({vec[j],j});
            }

            reverse(right_sm.begin(),right_sm.end());
            int ans1=0;

            for(int j=0;j<m;j++){

                int re= vec[j]*(right_sm[j]-left_sm[j]-1);
                ans1=max(ans1,re);
            }

            ans=max(ans,ans1);




        }
        return ans;
    }
};