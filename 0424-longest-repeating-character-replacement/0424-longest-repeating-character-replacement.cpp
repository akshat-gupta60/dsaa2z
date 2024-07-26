class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int>m;

        int n=s.size();
        int i=0,j=0;
        int ans=0;
        int ct=0;
        int mxfreq=0;
        while(j<n){

            m[s[j]]++;

            if(m[s[j]]>mxfreq){
                mxfreq=m[s[j]];
            }



            if(j-i+1-mxfreq<=k){
                ans=max(ans,j-i+1);
                j++;
            }
            else if(j-i+1-mxfreq>k){

                while(j-i+1-mxfreq>k){

                    m[s[i]]--;

                    mxfreq=0;
                    for(auto pr:m){
                        mxfreq=max(mxfreq,pr.second);
                    }
                    i++;
                }
                j++;

            }
        }
        return ans;
    }
};