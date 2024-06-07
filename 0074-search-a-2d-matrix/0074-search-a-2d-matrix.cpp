class Solution {
public:
    bool searchMatrix(vector<vector<int>>& v, int ta) {
        int n=v.size();
        int m=v[0].size();
        int i=0, j=m-1;
        while(i>=0 && i<n && j>=0 && j<m){
            int mid=v[i][j];

            if(mid==ta) return true;
            else if(mid<ta){
                i++;
            }
            else if(mid>ta){
                j--;
            }
        }
        return false;
    }
};