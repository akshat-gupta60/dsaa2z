class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int>nums1;

        for(int i=0;i<n;i++){
            nums1.push_back(nums[i]);
        }
         for(int i=0;i<n;i++){
            nums1.push_back(nums[i]);
        }

        stack<int>st;
        vector<int>v;

        for(int i=nums1.size()-1;i>=0;i--){

            if(st.size()==0){
                v.push_back(-1);
            }
            else if(st.size()>0 && st.top()>nums1[i]){
                v.push_back(st.top());
            }
            else if(st.size()>0 && st.top()<=nums1[i]){
                while(st.size()>0 && st.top()<=nums1[i]){
                    st.pop();
                }
                if(st.size()==0){
                    v.push_back(-1);
                }
                else{
                    v.push_back(st.top());
                }

            }
            st.push(nums1[i]);
        }

        reverse(v.begin(),v.end());
        int n2=v.size();

        for(int i=n;i<n2;i++){
            v.pop_back();
        } 
        // v.pop_back();
        return v;
    }
};