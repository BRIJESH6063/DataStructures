#include<bits/stdc++.h>
#include<iostream>
#include<Time.h>
using namespace std ;
#define ll long long
#define l  long
#define li long int 
#define d double
#define ld long double
#define read(x) int x ; cin >> x 
#define print(x) cout << x << " " 
#define readline(x) getline(cin, x) 

void sublimeInit() {
   #ifndef ONLINE_JUDGE
      freopen("input.txt", "r", stdin) ;
      freopen("output.txt", "w", stdout) ;
   #endif
}

// bool isPallindrome(string s, int i, int j) {
//    while(i < j) {
//       if(s[i] != s[j]) return false ;
//       i++ ; j-- ;
//    }
//    return true ;
// }

// // pallindrome partitioning 
// void pallin_partition(string s, vector<string> a, 
//    vector<vector<string>> &ans, int index=0) {
//    if(index == s.size()) {
//       ans.push_back(a) ;
//       return ;
//    }
//    for(int i=index; i<s.size(); i++) {
//       if(isPallindrome(s, index, i)) {
//          a.push_back(s.substr(index, i-index+1)) ;
//          pallin_partition(s, a, ans, i+1) ;
//          a.pop_back() ;
//       }
//    }
// }

























































































































































































int32_t main() {
   sublimeInit() ;

   string s = "aabbc" ;
   vector<string> a ;
   vector<vector<string>> ans ;
   pallin_partition(s, a, ans) ;
   for(auto x : ans) {
      for(auto y : x) cout << y << " " ;
         cout << endl ;
   }

















































































































































































































































   return 0 ;
}