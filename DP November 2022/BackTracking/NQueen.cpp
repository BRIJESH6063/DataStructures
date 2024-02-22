#include<bits/stdc++.h>
using namespace std;

bool isSafe(int row, int col, vector<string> board, int n) {
        int dupRow = row ;
        int dupCol = col ;
        // diagonal check upper
        while(dupRow >= 0 && dupCol >= 0) {
            if(board[dupRow][dupCol] == 'Q') return false ;
            dupRow -- ; dupCol -- ; 
        }
        
        dupRow = row ;
        dupCol = col ;
        // horizontal check ..
        while(dupCol >= 0) {
            if(board[dupRow][dupCol] == 'Q') return false ;
            dupCol -- ;
        }
        
        dupRow = row ;
        dupCol = col ;
        // lower diagonal check ..
        while(dupCol >= 0 && dupRow < n) {
            if(board[dupRow][dupCol] == 'Q') return false ;
            
            dupRow++ ; dupCol-- ;
        }
        return true ;
    }
    void solve(vector<string> &board, vector<vector<string>> &ans, int n, int col = 0) {
        if(col == n) {
            ans.push_back(board) ; return ;
        }
        for(int row=0; row<n; row++) {
            if(isSafe(row, col, board, n)) {
                board[row][col] = 'Q' ;
                solve(board, ans, n, col+1) ;
                board[row][col] = '.' ;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans ;
        vector<string> board(n) ;
        string s(n, '.') ;
        for(int i=0; i<n; i++) board[i] = s ;
        solve(board, ans, n) ;

        return ans ;
    }

int main()
{
    vector<vector<string>> ans = solveNQueens(4) ;
    for(auto x : ans) {
        cout << "---------------------------- " << endl ;
        for(auto y : x) cout << y << "    " << endl ;
        
    }
    
    
	return 0 ;
}