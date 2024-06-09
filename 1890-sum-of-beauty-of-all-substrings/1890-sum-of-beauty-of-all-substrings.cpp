class Solution {
public:
    int beautySum(string s) {
        int n=s.size();
        
        int ans=0;
        for(int i=0;i<n;i++){
            vector<int>freq(26,0);
            for(int j=i;j<n;j++){
                freq[s[j]-'a']++;

                int mx_freq=-1, min_freq=1e9;

                for(int it=0;it<26;it++){
                    if(freq[it]!=0){
                         mx_freq=max(mx_freq,freq[it]);
                        min_freq=min(min_freq,freq[it]);
                    }
                   
                }
                ans=ans+(mx_freq-min_freq);
            }
        }
        return ans;
    }
};