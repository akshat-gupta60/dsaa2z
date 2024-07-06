class Solution {
public:


    int countPrimes(int n) {

        long long n1=n;
        vector<int>sieve(n1+1,1);


        for(int i=2;i*i<=n1;i++){

            if(sieve[i]==1){
               

                for(long long j=i*i;j<=n1;j=j+(i)){
                    sieve[j]=0;
                }
            }
        }
        int ct=0;
        for(int i=2;i<n;i++){
            if(sieve[i]==1) ct++;
        }
        return ct;
    }
};