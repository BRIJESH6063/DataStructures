// Permutation by swapping approach .... 

#include<bits/stdc++.h>
using namespace std;

void permutation(vector<int> &arr, vector<vector<int>> &ans, int i=0) {
    int n = arr.size() ; 
    if(i == n) {
        vector<int> a ; 
        for(int j=0; j<n; j++) a.push_back(arr[j]) ;
        ans.push_back(a) ; return ;
    } 
    for(int j=i; j <n; j++) {
        swap(arr[i], arr[j]) ;
        permutation(arr, ans, i+1) ;
        swap(arr[i], arr[j]) ;
    }
}

int main()
{
    vector<int> arr({1, 2, 3, 4}) ;
    vector<vector<int>> ans ;
    permutation(arr, ans) ;
    for(auto x : ans ) {
        for(auto y : x) cout << y << " " ;
        cout << endl ;
    }
    
    
	return 0 ;
}