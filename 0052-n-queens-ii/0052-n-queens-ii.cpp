class Solution {
public:
    int queens(vector<string> &board, vector<bool> &colum, vector<bool> &leftD, vector<bool> &rightD, int n, int row){
        if(row==n){
            return 1;
        }

        int total = 0;

        for(int col = 0; col<n; col++){
            if(colum[col]==false && leftD[row-col+n-1]==false && rightD[row+col]==false){
                colum[col] = true;
                leftD[row-col+n-1] = true;
                rightD[row+col] = true;
                board[row][col] = 'Q';
                total = total+queens(board,colum,leftD,rightD,n,row+1);
                board[row][col] = '.';
                colum[col] = false;
                leftD[row-col+n-1] = false;
                rightD[row+col] = false;
                // return total;
            }
        }
        return total;
    }


    int totalNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        vector<bool> colum(n,false);
        vector<bool> leftD(2*n-1,false);
        vector<bool> rightD(2*n-1,false);
        return queens(board,colum,leftD,rightD,n,0);
        // return total;
    }
};