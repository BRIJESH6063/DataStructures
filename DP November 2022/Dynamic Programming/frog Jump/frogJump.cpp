// frog jump ... 

#include<bits/stdc++.h>
using namespace std ;

int f(vector<int> e, vector<int> &dp, int i) {
    if(i == 0) return 0 ;
    if(dp[i] != -1) return dp[i] ;
    int left = f(e, dp, i-1) + abs(e[i] - e[i-1]) ;
    int right = INT_MAX ;
    if(i > 1) right = f(e, dp, i-2) + abs(e[i] - e[i-2]) ;
    
    return dp[i] = min(left, right) ;
}

int frogJump(vector<int> &e, int n) {
    vector<int> dp(n+1, -1) ;
    return f(e, dp, n-1) ;
}

int main()
{
    vector<int> e({30, 10, 60, 10, 50}) ;
    cout << frogJump(e, e.size()) << endl ;
    return 0;
}