#include <bits/stdc++.h>
using namespace std;

// recurrence implementation ....
int maxSumPartition(vector<int> &arr, int i, int k) {
    int n = arr.size() ;
    if(i == n) return 0 ;
    int len = 0 ; int maxi = INT_MIN ;
    int maxAns = INT_MIN ;
    for(int j=i; j<min(n, i+k); j++) {
        len++ ;
        maxi = max(maxi, arr[j]) ;
        int sum = (len*maxi) + maxSumPartition(arr, j+1, k) ;
        maxAns = max(maxAns, sum) ;
    }
    return maxAns ;
}

// memoization implementation ....
int maxSumPartition(vector<int> &arr, int i, int k, vector<int> &dp) {
    int n = arr.size() ;
    if(i == n) return 0 ;
    if(dp[i] != -1) return dp[i] ;
    int len = 0 ; int maxi = INT_MIN ;
    int maxAns = INT_MIN ;
    for(int j=i; j<min(n, i+k); j++) {
        len++ ;
        maxi = max(maxi, arr[j]) ;
        int sum = (len*maxi) + maxSumPartition(arr, j+1, k, dp) ;
        maxAns = max(maxAns, sum) ;
    }
    return dp[i] = maxAns ;
}

int main() {
    vector<int> arr({1, 15, 7, 9, 2, 5, 10}) ;
	int n = arr.size() ; int k = 3 ;
    vector<int> dp(n, -1) ;
	cout << maxSumPartition(arr, 0, k, dp) << endl  ;
	return 0 ;
}


