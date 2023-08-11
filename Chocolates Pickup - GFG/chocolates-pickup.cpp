//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
  
  
    int rec(int i,int j1,int j2,vector<vector<int>>&grid,vector<vector<vector<int>>>&dp){
        
        int m=grid.size();
        int n=grid[0].size();
        if(j1<0||j1>=n||j2<0||j2>=n) return -1e8;
        if(i==m-1){
            if(j1==j2) return grid[i][j1];
            else return grid[i][j1]+grid[i][j2];
        }
        if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];
        
        int maxi=0;
        for(int d1=-1;d1<=1;d1++){
            for(int d2=-1;d2<=1;d2++){
                if(j1==j2) maxi=max(maxi,grid[i][j1]+rec(i+1,j1+d1,j2+d2,grid,dp));
                else maxi=max(maxi,grid[i][j1]+grid[i][j2]+rec(i+1,j1+d1,j2+d2,grid,dp));
            }
        }
        return dp[i][j1][j2]=maxi;
    }
    int solve(int m, int n, vector<vector<int>>& grid) {
        // code here
       
        //vector<vector<vector<int>>>dp(m,vector<vector<int>>(n,vector<int>(n,0)));
        vector<vector<int>>prev(n,vector<int>(n,0));
        for(int j1=0;j1<n;j1++){
            for(int j2=0;j2<n;j2++){
                if(j1==j2) prev[j1][j2]=grid[m-1][j1];
                else prev[j1][j2]=grid[m-1][j1]+grid[m-1][j2];
            }
        }
        
        for(int i=m-2;i>=0;i--){
            vector<vector<int>>curr(n,vector<int>(n,0));
            for(int j1=n-1;j1>=0;j1--){
                for(int j2=n-1;j2>=0;j2--){
                     int maxi=0;
                    for(int d1=-1;d1<=1;d1++){
                     for(int d2=-1;d2<=1;d2++){
                         int value=0;
                         if(j1==j2) value=grid[i][j1];
                        else value=grid[i][j1]+grid[i][j2];
                            
                        if(j1+d1<n&&j2+d2<n&&j1+d1>=0&&j2+d2>=0){
                            value=value+prev[j1+d1][j2+d2];
                        }
                        else value=-1e8;
                        
                        maxi=max(maxi,value);
                            
                            
            }
        }
        curr[j1][j2]=maxi;
                }
            }
            prev=curr;
        }
        return prev[0][n-1];
        
        // return rec(0,0,n-1,grid,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid;
        for (int i = 0; i < n; i++) {
            vector<int> temp;
            for (int j = 0; j < m; j++) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            grid.push_back(temp);
        }

        Solution obj;
        cout << obj.solve(n, m, grid) << "\n";
    }
    return 0;
}
// } Driver Code Ends