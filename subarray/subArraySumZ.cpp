// Subarray sum Problem  

#include<bits/stdc++.h>
using namespace std ;

bool isSumSubarray(int a[], int n, int sum)
{
    unordered_set<int> s ; //cout << "sum = " << sum << endl ;
    int pre_sum = 0 ;
    for(int i=0; i<n; i++){
        
        pre_sum += a[i] ;
        if(pre_sum == sum) return true ;
        if(s.find(pre_sum - sum) != s.end()) return true ;
        s.insert(pre_sum) ;
    }
    return false ;
}

int main()
{
    
    int n ; cin >> n ; int a[n] = {0} ;
    int sum ; cin >> sum ;
    for(int i=0; i<n; i++) cin >> a[i] ;
    
    bool ans = isSumSubarray(a, n, sum) ;
    cout << ans << endl ;
    
    return 0 ;
}