class Solution {
public:
    long long subArrayRanges(vector<int>& arr) {
         int n=arr.size();
         long long mod=1e9+7;
        stack<pair<long long,long long>>left_mn,right_mn,left_mx,right_mx;
        vector<long long >leftmn(n,0),rightmn(n,0),leftmx(n,0),rightmx(n,0);
        
        
        for(int i=0;i<n;i++){
            long long int ct=1;
            while(left_mn.size()!=0 && left_mn.top().first>arr[i]){
                ct=ct+left_mn.top().second;
                left_mn.pop();
                
            }
            left_mn.push({arr[i],ct});
            leftmn[i]=(ct);
            
            
        }

        for(int i=n-1;i>=0;i--){
            long long int ct=1;
            while(right_mn.size()!=0 && right_mn.top().first>=arr[i]){
                ct=ct+right_mn.top().second;
                right_mn.pop();
               
                
            }
             right_mn.push({arr[i],ct});
            rightmn[i]=(ct);
            
            
        }
         for(int i=0;i<n;i++){
            long long int ct=1;
            while(left_mx.size()!=0 && left_mx.top().first<arr[i]){
                ct=ct+left_mx.top().second;
                left_mx.pop();
                
            }
            left_mx.push({arr[i],ct});
            leftmx[i]=(ct);
            
            
        }

        for(int i=n-1;i>=0;i--){
            long long int ct=1;
            while(right_mx.size()!=0 && right_mx.top().first<=arr[i]){
                ct=ct+right_mx.top().second;
                right_mx.pop();
               
                
            }
             right_mx.push({arr[i],ct});
            rightmx[i]=(ct);
            
            
        }

        long long mn_sum=0,mx_sum=0;

        for(int i=0;i<n;i++){
            long long a=leftmn[i]*rightmn[i];
            mn_sum=(mn_sum+(a*arr[i]));
            long long b=leftmx[i]*rightmx[i];
            mx_sum=(mx_sum+(b*arr[i]));


        }

        long long int ans= mx_sum-mn_sum;
        return ans;
    }
};