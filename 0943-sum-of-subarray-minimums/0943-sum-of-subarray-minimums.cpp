class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        stack<pair<long long,long long>>left_mn,right_mn;
        vector<long long >left(n,0),right(n,0);
        long long mod=1e9+7;
        
        for(int i=0;i<n;i++){
            long long int ct=1;
            while(left_mn.size()!=0 && left_mn.top().first>arr[i]){
                ct=ct+left_mn.top().second;
                left_mn.pop();
                
            }
            left_mn.push({arr[i],ct});
            left[i]=(ct);
            
            
        }

        for(int i=n-1;i>=0;i--){
            long long int ct=1;
            while(right_mn.size()!=0 && right_mn.top().first>=arr[i]){
                ct=ct+right_mn.top().second;
                right_mn.pop();
               
                
            }
             right_mn.push({arr[i],ct});
            right[i]=(ct);
            
            
        }
        //reverse(right.begin(),right.end());

        // return left[3];
        int ans=0;

        for(int i=0;i<n;i++){

            long long a=(left[i]*right[i]);
            ans=(ans+a*arr[i])%mod;
        }
        return ans;


    }
};