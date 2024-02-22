// [ 1 0 1 1 1 0 0 ]  => [ 1 -1 1 1 1 -1 -1 ]
// Longest Subarray for sum = 0  
// longest Subarray with equal number of zeros and one 

#include<bits/stdc++.h>
using namespace std ;

int marLen(int a[], int n)
{
    unordered_map<int, int> m ; vector <int> v ; 
    int pre_sum = 0 ; int res = 0 ; cout << "res = " ;
    for(int i=0; i<n; i++){
        pre_sum += a[i] ; v.push_back(pre_sum) ; 
        if(pre_sum == 0) res = i+1 ;
        
        if(m.find(pre_sum) == m.end())
        m.insert(make_pair(pre_sum, i)) ;
        
        if(m.find(pre_sum) != m.end())
        res = max(res, i-m[pre_sum]) ;
        
        cout << res << " " ;
    } cout << endl ;
    for(int x : v) cout << x << "  " ;
    cout << endl ;
    return res ;
}

int main()
{
    
    int n ; cin >> n ; int a[n] = {0} ;
    for(int i=0; i<n; i++) cin >> a[i] ;
    for(int i=0; i<n; i++){
        if(!a[i]) a[i] = -1 ;
    }
    cout << marLen(a, n) << endl ;
    
    return 0 ;
}

/* Input -- 7
            1 0 1 1 1 0 0
            
            res = 0 2 2 2 2 2 6 
            1  0  1  2  3  2  1  
            6
*/
