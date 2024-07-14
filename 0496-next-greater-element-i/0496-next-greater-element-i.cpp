class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>v;
        int n=nums2.size();
        for(int i=0;i<nums2.size();i++){
            int a=-1;
            for(int j=i+1;j<n;j++){
                if(nums2[j]>nums2[i]){
                    a=nums2[j];
                    break;
                }
            }
            v.push_back(a);
        }

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