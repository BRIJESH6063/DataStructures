#include<bits/stdc++.h>
using namespace std ;

int main()
{
    vector<int> arr({1, 16, 7, 8, 4}) ;
    int n = arr.size() ;
    vector<int> dp(n, 1), hash(n, 0) ;
    int maxi = 0 ; int lastIndex = -1 ;
    sort(arr.begin(), arr.end()) ;
    for(int i=0; i<n; i++) {
        hash[i] = i ;
        for(int prev=0; prev<i; prev++) {
            if(arr[i]%arr[prev] == 0 && 1+dp[prev] > dp[i]) {
                dp[i] = 1 + dp[prev] ;
                hash[i] = prev ;
            }
        }
        if(dp[i] > maxi) {
            maxi = dp[i] ;
            lastIndex = i ;
        }
    }
    vector<int> temp ;
    temp.push_back(arr[lastIndex]) ;
    while(hash[lastIndex] != lastIndex) {
        lastIndex = hash[lastIndex] ;
        temp.push_back(arr[lastIndex]) ;
    }
    reverse(temp.begin(), temp.end()) ;
    for(auto x : temp ) cout << x << "  " ;
    cout << endl ;

    return 0 ;
}