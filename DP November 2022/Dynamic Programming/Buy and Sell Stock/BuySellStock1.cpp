#include<bits/stdc++.h>
using namespace std ;

int BuySellStock(vector<int> &arr) {
    int mini = arr[0] ; 
    int profit = 0 ; int n = arr.size() ;
    for(int i=1; i<n; i++) {
        int cost = arr[i] - mini ;
        profit = max(profit, cost) ;
        mini = min(mini, arr[i]) ;
    }

    return profit ;
}

int main() {
    vector<int> arr({7, 1, 5, 3, 6, 4}) ;
    cout << BuySellStock(arr) << endl ;

    return 0 ;
}