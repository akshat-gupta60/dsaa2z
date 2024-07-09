class Solution {
public:
    double myPow(double x, int n) {
        
       
        long long int n1=abs(n);

        
        double res=1;

        while(n1){
            if(n1%2==0){
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