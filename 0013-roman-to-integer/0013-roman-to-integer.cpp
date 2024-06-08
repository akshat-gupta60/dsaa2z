class Solution {
public:
    int romanToInt(string s) {
        map<char,int>m;
        int sum=0;
        int n=s.size();
        m['I']=1;
        m['V']=5;
        m['X']=10;
        m['L']=50;
        m['C']=100;
        m['D']=500;
        m['M']=1000;

        for(int i=0;i<n;i++){

            if(s[i]=='I'){
                if(i+1<n && s[i+1]=='V'){
                    sum=sum+4;
                    i++;
                }
                else if(i+1<n && s[i+1]=='X'){
                    sum=sum+9;
                    i++; 
                }
                else {
                    sum=sum+1;
                }
            }
            else if(s[i]=='X'){
                if(i+1<n && s[i+1]=='L'){
                    sum=sum+40;
                    i++;
                }
                else if(i+1<n && s[i+1]=='C'){
                    sum=sum+90;
                    i++; 
                }
                else{
                    sum=sum+10;
                }
            }
             else if(s[i]=='C'){
                if(i+1<n && s[i+1]=='D'){
                    sum=sum+400;
                    i++;
                }
                else if(i+1<n && s[i+1]=='M'){
                    sum=sum+900;
                    i++; 
                }
                else{
                    sum=sum+100;
                }
            }
            else if(s[i]=='V'){
                sum=sum+5;
            }
            else if(s[i]=='L'){
                sum=sum+50;
            }
            else if(s[i]=='D'){
                sum=sum+500;
            }
            else if(s[i]=='M'){
                sum=sum+1000;
            }
            


        }

        return sum;
    }
};