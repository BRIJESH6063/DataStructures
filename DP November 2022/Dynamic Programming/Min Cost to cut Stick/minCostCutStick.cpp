#include<bits/stdc++.h>
using namespace std ;

// Minimum cost to cut stick ....
// Recurrence implementation ....
int MinimumCostStick(vector<int> &cost, int i, int j) {
    if(i > j) return 0 ;
    int mini = INT_MAX ;
    for(int ind=i; ind<=j; ind++) {
        int find = (cost[j+1]-cost[i-1]) +
        MinimumCostStick(cost, i, ind-1) + MinimumCostStick(cost, ind+1, j) ;
        mini = min(mini, find) ;
    }
    return mini ;
}

// memoization implementation ... 
int MinimumCostStick(vector<int> &cost, int i, int j, vector<vector<int>> &dp) {
    if(i>j) return 0 ;
    int mini = 1e9 + 7 ;
    if(dp[i][j] != -1) return dp[i][j] ;
    for(int ind=i; ind<=j; ind++) {
        int find = (cost[j+1]-cost[i-1]) + 
        MinimumCostStick(cost, i, ind-1, dp) + MinimumCostStick(cost, ind+1, j, dp) ;
        mini = min(mini, find) ;
    }
    return dp[i][j] = mini ;
}

// Tabulation Implementation ...  
int MinimumCostStick(vector<int> &cuts) {
    int n=cuts.size() ; 
    vector<vector<int>> dp(n, vector<int>(n, 0)) ;
    for(int i=n-2; i>=1; i--) {
        for(int j=1; j<=n-2; j++) {
            if(i>j) continue ; 
            int mini = INT_MAX ;
            for(int ind=i; ind<=j; ind++) {
                int find = (cuts[j+1]-cuts[i-1]) + dp[i][ind-1] + dp[ind+1][j] ;
                mini = min(mini, find) ;
            }
            dp[i][j] = mini ;
        }
    }
    return dp[1][n-2] ;
}

int main()
{
    vector<int> cost({5,6,1,4,2}) ; int k = 9 ;
    cost.insert(cost.begin(), 0) ; cost.push_back(k) ;
    sort(cost.begin(), cost.end()) ;
    // int n = cost.size() ;
    // vector<vector<int>> dp(n-1, vector<int>(n-1, -1)) ;
    cout << MinimumCostStick(cost) << endl ;
    
    return 0 ;
}