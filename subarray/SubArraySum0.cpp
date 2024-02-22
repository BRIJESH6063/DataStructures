// Subarray with zero sum array (distinct) 
// [ -3,  4,  -3,  -1,  1  ]
//    a0, a1, .... ai-1,  ai, ai+1  .....  aj 
//    <-PreSum1.....->    <-....Sum[i:j]...->
//    <-............PreSum2................->   
// if Sum[i:j] = 0 , PreSum1 = PreSum2  

#include<bits/stdc++.h>
using namespace std ;

bool isZeroSubarray(int a[], int n)
{
    bool ans = false ;   vector<int> pre ;
    unordered_set<int> h ;
    int pre_sum = 0 ;  int x = 0 ; int y = 0 ;
    for(int i=0; i<n; i++){
        pre_sum += a[i] ;  pre.push_back(pre_sum) ;
        //cout << pre_sum << "  " ;
        if(h.find(pre_sum) != h.end()){
            auto it = h.find(pre_sum) ; x = *it ; y = i ;
            ans = true ; break ;
        }
        if(pre_sum == 0) {
            ans = true ; break ;
        } 
        h.insert(pre_sum) ;
    }
    // cout << "x = " << x << " y = " << y << endl ;
    // for(auto a : pre) cout << a << "  " ;
    // cout << endl ;
    // for(int i =x; i<=y; i++) cout << a[i] << "  " ;
    //cout << endl ;
    return ans ;
    
}

int main()
{
    
    int n ; cin >> n ; int a[n] = {0} ;
    for(int i=0; i<n; i++) cin >> a[i] ;
    
    bool ans = isZeroSubarray(a, n) ;
    cout << ans << endl ;
    
    return 0 ;
}