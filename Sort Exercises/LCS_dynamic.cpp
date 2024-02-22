#include<bits/stdc++.h>
using namespace std ;

bool isSubset(int a[], int n, int sum)
{
    bool subset[n+1][sum+1] ;
    for(int i=0; i<n+1; i++) subset[i][0] = true ;
    for(int i=0; i<n+1; i++){
        for(int j=0; j<=sum; j++) cout << subset[i][j] << "  " ;
        cout << endl ;
    }
    for(int i=1; i<=sum; i++) subset[0][i] = false ;
    for(int i=0; i<n+1; i++){
        for(int j=0; j<=sum; j++) cout << subset[i][j] << "  " ;
        cout << endl ;
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=sum; j++){
            if(j < a[i-1]) subset[i][j] = subset[i-1][j] ;
            if(j >= a[i-1]) subset[i][j] = subset[i-1][j] || subset[i-1][j-a[i-1]] ;
        }
    }

    for(int i=0; i<n+1; i++){
        for(int j=0; j<=sum; j++) cout << subset[i][j] << "  " ;
        cout << endl ;
    }

    return subset[n][sum] ;
}

int main()
{
    int a[] = {4,2,6,7,9,1,4,3} ;
    int n = sizeof(a)/sizeof(a[0]) ;
    int sum = 5 ;
    if(isSubset(a, n, sum)) cout << "Subset is found with required sum : " << endl ;
    else cout << "Subset is not found with required sum : " << endl ;

    return 0 ;
}