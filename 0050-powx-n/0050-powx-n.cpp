class Solution {
public:
    double myPow(double x, int n) {
        
        if(x==1) return 1.00;
        long long int n1=n;

        if(n<0) n1=(-1)*n1;
        double res=1;

        while(n1){
            if((n1&1)==0){
                x=x*x;
                n1=n1/2;
            }
            else{
                res=res*x;
                n1=n1-1;
            }
        }

        if(n>0){
            return (res);

        }
        return 1/res;
    }
};