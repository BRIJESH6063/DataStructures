#include<bits/stdc++.h>
using namespace std ;

int TabulationFJ(vector<int> &height, int n) {
    int prev = 0 ; int prev2 = 0 ;
    for(int i=1; i<n; i++) {
        int fs = prev + abs(height[i]-height[i-1]) ;
        int ss = INT_MAX ;
        if(i > 1) ss = prev2 + abs(height[i] - height[i-2]) ;

        int curr = min(fs, ss) ;
        prev2 = prev ;
        prev = curr ;
    }


    return prev ;
}

int main() 
{
    vector<int> height({30, 10, 60, 60, 50}) ;
    cout << TabulationFJ(height, height.size()) << endl ;


    return 0 ;
}