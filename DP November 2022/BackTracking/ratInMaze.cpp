// Rat in a maze Problem .... 

#include<bits/stdc++.h>
using namespace std ;

void solve(vector<vector<int>> &m, int n, vector<vector<int>> &v, vector<string > &ans, string move,  int i=0, int j=0){
    if(i == n-1 && j == n-1) {
        ans.push_back(move) ; return ;
    }
    // downword ... 
    if(i+1 < n && !(v[i+1][j]) && m[i+1][j] == 1)  {
        v[i][j] = 1 ;
        solve(m, n, v, ans, move+'D', i+1, j) ;
        v[i][j] = 0 ;
    }
    // left ... 
    if(j-1 >= 0 && !(v[i][j-1]) && m[i][j-1] == 1)  {
        v[i][j] = 1 ;
        solve(m, n, v, ans, move+'L', i, j-1) ;
        v[i][j] = 0 ;
    }
    // right ... 
    if(j+1 < n && !(v[i+1][j]) && m[i][j+1] == 1)  {
        v[i][j] = 1 ;
        solve(m, n, v, ans, move+'R', i, j+1) ;
        v[i][j] = 0 ;
    }
    // Upward ... 
    if(i-1 >= 0 && !(v[i-1][j]) && m[i-1][j] == 1)  {
        v[i][j] = 1 ;
        solve(m, n, v, ans, move+'U', i-1, j) ;
        v[i][j] = 0 ;
    }
}

vector<string> findpath(vector<vector<int>> &m, int n) {
    vector<string> ans ; 
    vector<vector<int>> v(n, vector<int>(n,0)) ;
    string move = "" ;
    
    if(m[0][0] = 1) solve(m, n, v, ans, move) ;
    return ans ;
}

int main()
{
    
    
    return 0;
}