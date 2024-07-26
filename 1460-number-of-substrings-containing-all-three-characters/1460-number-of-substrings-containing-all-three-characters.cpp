class Solution {
public:

    int func(string &s){
 int i=0,j=0;
        int n=s.size();
        int ct=0;
        map<char,int>m;

        while(j<n){
            m[s[j]]++;

            if(m.size()<3){
                
                j++;
            }
            else if(m.size()==3){

                
                while(m.size()==3){
                    ct=ct+(n-j);
                    m[s[i]]--;
                    if(m[s[i]]==0){
                        m.erase(s[i]);
                    }
                    i++;
                }
                j++;
            }
        }

      

        return ct;
    
    }
    int numberOfSubstrings(string s) {

        int a=func(s);
        reverse(s.begin(),s.end());
        int b=func(s);
        return max(a,b);
    }
};