class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {
        vector<int>ans;
        stack<int>st;
        int n=arr.size();

        for(int i=0;i<n;i++){

            if(st.size()!=0 && st.top()>0 && arr[i]<0){
                while(st.size()>0 && st.top()>0 && st.top()<abs(arr[i])){
                    st.pop();
                    
                }
                if(st.size()==0) st.push(arr[i]);
                else if(st.top()<0) st.push(arr[i]);
                else if(st.top()==abs(arr[i])) st.pop();



               
            }

            else if(st.size()==0) st.push(arr[i]);
            else if(st.size()!=0 && st.top()>0 && arr[i]>0) st.push(arr[i]);
            else if(st.size()!=0 && st.top()<0 && arr[i]<0) st.push(arr[i]);
            else if(st.size()!=0 && st.top()<0 && arr[i]>0) st.push(arr[i]);
        }

        while(st.size()!=0){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};