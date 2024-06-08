class Solution {
public:
    string reverseWords(string s) {
     int n=s.size();
     vector<int>v_ind_spaces;


     for(int i=0;i<s.size();i++){
        if(s[i]!=' ') break;

        if(s[i]==' '){
            s.erase(s.begin());
            i--;
        }
     }

     for(int i=0;i<s.size();i++){
        if(i+1<s.size() && s[i]==' ' && s[i+1]==' '){
            s.erase(s.begin()+i+1);
            i--;
        }
     }

     reverse(s.begin(), s.end());



     int left=0, right=0;

     for(int i=0;i<n;i++){
        if(s[i]==' '){
            right=i;
            reverse(s.begin()+left, s.begin()+right);
            left=i+1;
        }
     }
     reverse(s.begin()+left,s.end());
    
      for(int i=0;i<s.size();i++){
        if(s[i]!=' ') break;

        if(s[i]==' '){
            s.erase(s.begin());
            i--;
        }
     }
   
     return s;


    }
};