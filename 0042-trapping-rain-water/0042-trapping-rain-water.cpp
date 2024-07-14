class Solution {
public:
    int trap(vector<int>& v) {
        int n=v.size();
        int left=0,right=n-1;
        int left_max=0,right_max=0;
        int ans=0;
        while(left<=right){

            if(v[left]<=v[right]){
                if(v[left]>left_max) left_max=v[left];
                else {
                    ans=ans+(left_max-v[left]);
                }
                left++;
            }
            else{
                if(v[right]>right_max) right_max=v[right];
                else{
                    ans=ans+(right_max-v[right]);
                }
                right--;
            }
        }
        return ans;
    }
};