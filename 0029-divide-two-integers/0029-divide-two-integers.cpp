class Solution {
public:
    int divide(int dividend, int divisor) {
        

        bool sign=true;

        if(dividend>=0 && divisor<0) sign=false;
        if(dividend<0 && divisor>0) sign=false;

        long int n=abs(dividend);
        long int d=abs(divisor);

        long int ans=0;
        while(n>=d){

            int ct=0;

            while(n>=(d<<(ct+1))){
                ct++;
                
            }

            ans=ans+(1<<ct);
            n=n-(d<<ct);

        }

        if(ans==(1<<31) && sign==true) return INT_MAX;
         if(ans==(1<<31) && sign==false) return INT_MIN;

         return (sign==true)? ans:(-1*ans);




    }
};