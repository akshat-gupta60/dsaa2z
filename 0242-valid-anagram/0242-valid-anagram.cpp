class Solution {
public:
    bool isAnagram(string s, string t) {

        int n=s.size();
        int m=t.size();
        if(m!=n) return false;
        vector<int>v1(26,0);
        vector<int>v2(26,0);

        for(int i=0;i<n;i++){
            v1[s[i]-'a']++;
        }
        for(int i=0;i<m;i++){
            v2[t[i]-'a']++;
        }

        for(int i=0;i<26;i++){
            if(v1[i]!=v2[i]) return false;
        }
        return true;
    }
};