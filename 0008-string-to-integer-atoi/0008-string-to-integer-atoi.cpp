class Solution {
public:
    int myAtoi(string s) {
        string st="";
        int n=s.size();
        int start_ind=0;
        int is_plus=0;
        for(int i=0;i<n;i++){
            if(s[i]==' '){
                continue;
            }
            
            else{
                start_ind=i;
                break;
            }
        }
        for(int i=start_ind;i<n;i++){
            if(s[i]=='+'){
                is_plus=is_plus+1;
                continue;
            }
            
            else{
                start_ind=i;
                break;
            }
        }


        int is_neg=0;
        

        for(int i=start_ind;i<n;i++){
            if(s[i]=='-'){
                is_neg=is_neg+1;
                continue;
            }
            else{
                start_ind=i;
                break;
            }
        }
        // if(s[start_ind]=='-'){
        //     is_neg=is_neg+1;
        //     start_ind++;
            
        // }

        if(is_neg>=1 && is_plus>=1) return 0;
        if(is_neg>1|| is_plus>1) return 0; 
        
        
        for(int i=start_ind;i<n;i++){
            if(s[i]>='0' && s[i]<='9' ){
                st.push_back(s[i]);
            }
            else break;
        }
        
        long long int sum=0;
        for(int i=0;i<st.size();i++){
            sum=sum*10+(st[i]-'0');
            if(sum>INT_MAX){
                if(is_neg==1) return INT_MIN;
                return INT_MAX;
            }
            
        }
        if(is_neg==1){
            sum=(-1)*sum;
        }
        
        if(sum>=INT_MIN && sum<=INT_MAX) return sum;
        else if(sum<(INT_MIN)) return INT_MIN;
        return INT_MAX;
    







    }
};