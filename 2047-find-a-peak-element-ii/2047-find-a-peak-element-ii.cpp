class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& v) {
        

        int n=v.size();
        int m=v[0].size();

        
        int start=0, end=m-1;

        while(start<=end){
            int mid=start+(end-start)/2;
            int mxvalue=-1;
            int mx_ind=0;
            for(int i=0;i<n;i++){
                if(mxvalue<v[i][mid]){
                    mxvalue=v[i][mid];
                    mx_ind=i;
                }

            }
            
            bool leftIsBig = (mid - 1 >= 0 && v[mx_ind][mid - 1] > v[mx_ind][mid]);
            bool rightIsBig = (mid + 1 < m && v[mx_ind][mid + 1] > v[mx_ind][mid]);

            // If the middle element is greater than its neighbors, it is a peak
            if (!leftIsBig && !rightIsBig) {
                return {mx_ind, mid};
            } else if (leftIsBig) {
                end = mid - 1; // Move to the left half
            } else {
                start = mid + 1; // Move to the right half
            }
        
        }
        return {};
    }
};