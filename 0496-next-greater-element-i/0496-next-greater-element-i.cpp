class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>v;
        int n=nums2.size();

        stack<int>st;
        for(int i=n-1;i>=0;i--){
            if(st.size()==0){
                v.push_back(-1);
            }
            else if(st.size()>0 && st.top()>nums2[i]){
                v.push_back(st.top());
            }
            else if(st.size()>0 && st.top()<=nums2[i]){

                while(st.size()>0 && st.top()<=nums2[i]){
                    st.pop();
                }

                if(st.size()==0){
                    v.push_back(-1);
                }
                else{
                    v.push_back(st.top());
                }
            }
            st.push(nums2[i]);
        }
        reverse(v.begin(),v.end());
        unordered_map<int,int>m;

        for(int i=0;i<nums2.size();i++){
            m[nums2[i]]=i;
        }

        vector<int>ans;

        for(int i=0;i<nums1.size();i++){
            ans.push_back(v[m[nums1[i]]]);
        }
        return ans;
    }
};