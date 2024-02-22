// Longest Subarray for given sum   

#include<bits/stdc++.h>
using namespace std ;

int marLen(int a[], int n, int sum)
{
    unordered_map<int, int> m ; vector <int> v ; vector <int> v1 ;
    int pre_sum = 0 ; int res = 0 ; cout << "res = " ;
    for(int i=0; i<n; i++){
        pre_sum += a[i] ; v.push_back(pre_sum) ; v1.push_back(pre_sum - sum) ; 
        if(pre_sum == sum) res = i+1 ;
        
        if(m.find(pre_sum) == m.end())
        m.insert(make_pair(pre_sum, i)) ;
        
        if(m.find(pre_sum-sum) != m.end())
        res = max(res, i-m[pre_sum-sum]) ;
        
        cout << res << " " ;
    } cout << endl ;
    for(int x : v) cout << x << "  " ;
    cout << endl ;
    for(int x : v1) cout << x << "  " ;
    cout << endl ;
    return res ;
}

int main()
{
    
    int n ; cin >> n ; int a[n] = {0} ;
    int sum ; cin >> sum ;
    for(int i=0; i<n; i++) cin >> a[i] ;
    
    cout << marLen(a, n, sum) << endl ;
    
    return 0 ;
}

/* Input -- 8 4
            8 3 1 5 -6 6 2 2
            
    Output -- 
    res = 0 0 2 2 2 2 2 4 
    8  11  12  17  11  17  19  21  
    4  7  8  13  7  13  15  17  
    4
    
*/
