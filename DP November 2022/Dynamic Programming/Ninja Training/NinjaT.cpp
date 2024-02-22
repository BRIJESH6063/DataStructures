#include<bits/stdc++.h> 
using namespace std ;

// Recursive implementation .... 
int ninjaT(vector<vector<int>> &task, int day, int last) {
    // cout << "visited day : " << day << endl ;
    if(day == 0) {
        int maxi = 0 ;
        for(int i=0; i<3; i++) 
        if(i != last) maxi = max(maxi, task[0][i]) ;
        return maxi ;
    }

    int maxi = 0 ;
    for(int i=0; i<3; i++) {
        if(i != last) {
            int points = task[day][i] + ninjaT(task, day-1, i) ;
            maxi = max(maxi, points) ;
        }
    }
    return maxi ;
}

// memoizatioin implementation .... 
int ninjaT(vector<vector<int>> &task, vector<vector<int>> &dp, int day, int last) {
    // cout << "visited day : " << day << endl ;
    if(day == 0) {
        int maxi = 0 ;
        for(int i=0; i<3; i++) 
        if(i != last) maxi = max(maxi, task[0][i]) ;
        return maxi ;
    }

    if(dp[day][last] != -1) return dp[day][last] ;

    int maxi = 0 ;
    for(int i=0; i<3; i++) {
        if(i != last) {
            int points = task[day][i] + ninjaT(task, dp, day-1, i) ;
            maxi = max(maxi, points) ;
        }
    }
    return dp[day][last] = maxi ;
}

// Tabulation implementation ......... 
int NinjaTab(vector<vector<int>> &task) {
    int n = task.size() ;
    vector<vector<int>> dp(n, vector<int>(4, 0)) ;
    dp[0][0] = max(task[0][1], task[0][2]) ;
    dp[0][1] = max(task[0][0], task[0][2]) ;
    dp[0][2] = max(task[0][1], task[0][0]) ;
    dp[0][3] = max(task[0][0], max(task[0][1], task[0][2])) ;

    for(int day = 1; day <n; day++) {
        for(int last = 1; last <4; last++) {
            dp[day][last] = 0 ; int maxi = 0 ;
            for(int i=0; i<3; i++) {
                if(i != last) {
                    int point = task[day][i] + dp[day-1][i] ;
                    dp[day][last] = max(dp[day][last], point) ;
                }
            }
        }
    }

    return dp[n-1][3] ;
}


int main() 
{
    vector<vector<int>> task({{2, 1, 3},
                              {3, 4, 6},
                              {10, 1, 6},
                              {4, 1, 7}}) ;
    int day = task.size() ; int n = task.size() ;
    vector<vector<int>> dp(n, vector<int>(4, -1)) ;
    // cout << "Hello1 ...." << endl ;
    // cout << ninjaT(task, day-1, 3) << endl ;
    // cout << "Hello2 ...." << endl ;
    // cout << ninjaT(task, dp, day-1, 3) << endl ;
    // Tabulation solution .....
    cout << NinjaTab(task) << endl ;

    return 0 ;
}