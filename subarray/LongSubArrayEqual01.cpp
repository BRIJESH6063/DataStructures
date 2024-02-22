// Longest Subarray with equal number of 0s and 1s
// Naive Solution 

#include<bits/stdc++.h>
using namespace std ;

int longestSub(int a[], int n)
{
    int res = 0 ; //cout << "max = " ; //int x = 0 ; int y = 0 ;
    for(int i=0; i<n; i++){
        int c0 = 0 ; int c1 = 0 ;
        for(int j=i; j<n; j++){
            if(a[j] == 0) c0++ ;
            else c1++ ;
            
            if(c0 == c1) res = max(res, j-i+1) ;
        }
        //x = c0 ; y = c1 ;
        //cout << res << " " ;
    }
    //cout << endl ; cout << "c0 = " << x << " c1 = " << y << endl ;
    return res ;
}

int main()
{
    int n ; cin >> n ; int a[n] = {0} ;
    for(int i=0; i<n; i++) cin >> a[i] ;
    
    cout << longestSub(a, n) << endl ;
    
    return 0 ;
}