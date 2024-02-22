#include<bits/stdc++.h>
using namespace std ;

// Recursion implementation ....
void subset2(vector<int> &arr, vector<int> &a, vector<vector<int>> &ans, int i=0){
    
}

// BitMask implementation ......
vector<vector<int>> SubsetBitMask(vector<int> &arr) {
    int n = arr.size() ;
    int counter = pow(2, n) ;
    vector<vector<int>> ans ;
    for(int i=0 ; i<n; i++) {
        vector<int> subsets ;
        for(int j=0; j<counter; j++) {

        }
    }
}

int main()
{
    vector<int> arr({1, 2, 2}) ;
    vector<int> a ; vector<vector<int>> ans ;
    subset2(arr, a, ans) ;
    for(auto x : ans) {
        for(auto y : x) cout << y << " "  ;
        cout << endl ;
    }


    return 0 ;
}