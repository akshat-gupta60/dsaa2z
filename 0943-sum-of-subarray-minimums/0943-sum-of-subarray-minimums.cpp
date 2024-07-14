class Solution {
public:
    int sumSubarrayMins(vector<int>& a) {
        int n=a.size();
        vector<long long>minleft(n,0);
        vector<long long>minright(n,0);
        stack<pair<int,int>>lf;
        stack<pair<int,int>>rt;
        for(int i=0;i<n;i++){
            int ct=1;
            while(lf.size()!=0&&lf.top().first>a[i]){
                ct=ct+lf.top().second;
                lf.pop();
            }
            lf.push(make_pair(a[i],ct));
            minleft[i]=ct;
        }
         for(int i=n-1;i>=0;i--){
            int ct=1;
            while(rt.size()!=0&&rt.top().first>=a[i]){
                ct=ct+rt.top().second;
                rt.pop();
            }
            rt.push(make_pair(a[i],ct));
            minright[i]=ct;
        }
        long long sum=0;
        long long m=1000000007;
        for(int i=0;i<n;i++){
            long long b=(minleft[i])*(minright[i]);
            long long c=(a[i]*b);
            sum=(sum+c)%m;
        }
        return sum;
    }
};