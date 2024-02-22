#include<bits/stdc++.h>
using namespace std ;

// recurrence implementation ....
int maxCoinsBBalloon(vector<int> &coin, int i, int j) {
    if(i > j) return 0 ;
    int maxi = INT_MIN ;
    for(int ind=i; ind<=j; ind++) {
        int coins = (coin[i-1]*coin[ind]*coin[j+1]) 
        + maxCoinsBBalloon(coin, i, ind-1) + maxCoinsBBalloon(coin, ind+1, j) ;
        maxi = max(maxi, coins) ;
    }
    return maxi ;
}

// memoization implementation ....
int maxCoinsBBalloon(vector<int> &coin, int i, int j, vector<vector<int>> &dp) {
    if(i > j) return 0 ;
    if(dp[i][j] != -1) return dp[i][j] ;
    int maxi = INT_MIN ;
    for(int ind=i; ind<=j; ind++) {
        int coins = (coin[i-1]*coin[ind]*coin[j+1]) 
        + maxCoinsBBalloon(coin, i, ind-1, dp) + maxCoinsBBalloon(coin, ind+1, j, dp) ;
        maxi = max(maxi, coins) ;
    }
    return dp[i][j] = maxi ;
}

// Tabulation implementation ....
int maxCoinsBBalloon(vector<int> &coin) {
    int n = coin.size() ;
    vector<vector<int>> dp(n-1, vector<int>(n-1, 0)) ;
    for(int i=n-2; i>=1; i--) {
        for(int j=1; j<=n-2; j++) {
            if(i > j) continue ;
            int maxi = INT_MIN ;
            for(int ind=i; ind<=j; ind++) {
                int coins = (coin[i-1]*coin[ind]*coin[j+1]) 
                + maxCoinsBBalloon(coin, i, ind-1, dp) + maxCoinsBBalloon(coin, ind+1, j, dp) ;
                maxi = max(maxi, coins) ;
            }
            dp[i][j] = maxi ;
        }
    }
    return dp[1][n-2] ;
}

int main()
{
    vector<int> coin({3, 1, 5, 8}) ;
    coin.insert(coin.begin(), 1) ; coin.push_back(1) ;
    // int n = coin.size() ;
    // vector<vector<int>> dp(n-1, vector<int>(n-1, -1)) ;
    cout << maxCoinsBBalloon(coin) << endl ;

    return 0 ;
}