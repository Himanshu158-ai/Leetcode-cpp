// class Solution {
// public:

//     bool isSafe(int row, int col, vector<string>& board,int n){
//         for(int i = 0; i<n; i++){
//             if(board[i][col]=='Q') return false;
//         }

//         int i = row,j = col;
//         while(i>=0 && j>=0){
//             if(board[i][j]=='Q') return false;
//             i--,j--;
//         }

//         i = row,j = col;
//         while(i>=0 && j<n){
//             if(board[i][j]=='Q') return false;
//             i--,j++;
//         }
//         return true;
//     }

//     void queens(vector<vector<string>> &ans, int n, int row, vector<string>& board){
//         if(row==n){
//             ans.push_back(board);
//             return;
//         }

//         for(int col = 0; col<n; col++){
//             if(isSafe(row,col,board,n)){
//                 board[row][col]='Q';
//                 queens(ans,n,row+1,board);
//                 board[row][col]='.';
//             }
//         }
//         return;
//     }

//     vector<vector<string>> solveNQueens(int n) {
//         vector<string> board(n, string(n, '.'));
//         vector<vector<string>> ans;
//         queens(ans, n, 0,board);
//         return ans;
//     }
// };


class Solution {
public:

    bool isSafe(int row, int col, vector<string>& board,int n,vector<int> &coll, vector<int> &leftD, vector<int> &rightD){
        if(coll[col]==1) return false;
        if(leftD[row-col+n-1]==1) return false;
        if(rightD[row+col]==1) return false;
        return true;
    }

        void queens(vector<vector<string>> &ans, int n, int row, vector<string>& board, vector<int> &coll, vector<int> &leftD, vector<int> &rightD){
        if(row==n){
            ans.push_back(board);
            return;
        }

        for(int col = 0; col<n; col++){
            if(isSafe(row,col,board,n,coll,leftD,rightD)){
                board[row][col]='Q';
                coll[col] = 1;
                leftD[row-col+n-1] = 1;
                rightD[row+col] = 1;
                queens(ans,n,row+1,board,coll,leftD,rightD);
                board[row][col]='.';
                coll[col] = 0;
                leftD[row-col+n-1] = 0;
                rightD[row+col] = 0;
            }
        }
        return;
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        vector<vector<string>> ans;
        vector<int> coll(n);
        vector<int> leftD(2*n-1);
        vector<int> rightD(2*n-1);
        queens(ans, n, 0,board,coll,leftD,rightD);
        return ans;
    }

};