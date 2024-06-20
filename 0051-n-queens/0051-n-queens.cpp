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

    void rec(int col, vector<string>&board, vector<vector<string>>&ans){
        if(col==board[0].size()){
            ans.push_back(board);
            return ;
        }

        for(int row=0;row<board.size();row++){

            if(check(board,row,col)==true){
                board[row][col]='Q';
                rec(col+1,board,ans);
                board[row][col]='.';

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

        rec(0,board,ans);
        return ans;

    }
};