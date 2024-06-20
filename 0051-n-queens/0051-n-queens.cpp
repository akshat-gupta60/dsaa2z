class Solution {
public:
    bool check(vector<string>&board,int row, int col){
        int n=board.size();
        int dumrow=row;
        int dumcol=col;

        //left check

        while(dumcol>=0){
            if(board[dumrow][dumcol]=='Q') return false;
            dumcol--;
        }
        dumrow=row;
        dumcol=col;
        //lower diagonal
        while(dumcol>=0 && dumrow<n){
            if(board[dumrow][dumcol]=='Q') return false;
            dumcol--;
            dumrow++;
        }

        //upper diagonal

        dumrow=row;
        dumcol=col;
         while(dumcol>=0 && dumrow>=0){
            if(board[dumrow][dumcol]=='Q') return false;
            dumcol--;
            dumrow--;
        }

        return true;



    }

    void rec(int col, vector<string>&board, vector<vector<string>>&ans, vector<int>&left, vector<int>&upper_d, vector<int>&lower_d){
        if(col==board[0].size()){
            ans.push_back(board);
            return ;
        }

        for(int row=0;row<board.size();row++){

            if(left[row]==0&& upper_d[board.size()-1+col-row]==0 && lower_d[row+col]==0){
                board[row][col]='Q';
                left[row]=1;
                upper_d[board.size()-1+col-row]=1;
                lower_d[row+col]=1;
                rec(col+1,board,ans,left,upper_d,lower_d);
                board[row][col]='.';
                 left[row]=0;
                upper_d[board.size()-1+col-row]=0;
                lower_d[row+col]=0;

            }
        }


    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string>board;

        string s="";
        for(int i=0;i<n;i++){
            s.push_back('.');
        }
        for(int i=0;i<n;i++){
            board.push_back(s);
        }

        vector<vector<string>> ans;
        vector<int>left(n,0);
        vector<int>upper_d(n+n,0);
        vector<int>lower_d(n+n,0);

        rec(0,board,ans,left,lower_d, upper_d);
        return ans;

    }
};