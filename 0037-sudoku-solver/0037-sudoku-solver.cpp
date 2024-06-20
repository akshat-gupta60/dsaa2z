class Solution {
public:
    bool check(vector<vector<char>>&board, int row, int col, int val){

        for(int i=0;i<9;i++){
            if(board[row][i]==val) return false;
            if(board[i][col]==val) return false;

            if(board[3*(row/3)+(i/3)][3*(col/3)+(i%3)]==val) return false;
            
        }
        return true;
    }

    bool rec(vector<vector<char>>&board){


        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.'){
                    for(char a='1';a<='9';a++){
                        if(check(board,i,j,a)){
                            board[i][j]=a;

                            if(rec(board)==true){
                                return true;
                            }
                            else{
                                board[i][j]='.';
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;

    }
    void solveSudoku(vector<vector<char>>& board) {
        bool a= rec(board);
        
    }
};