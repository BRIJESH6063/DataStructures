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

string fsum(string &sum, string &ans) {
  int x = sum.size() - ans.size() + 1 ;
  string ans1 = "" ;
  while(x--) ans1.push_back('0') ;
  ans1.push_back('0') ;
  x = ans.size() ;
  while(x--) ans1.push_back(ans[ans.size()-x]) ;
  int carry = 0 ;
  x = sum.size() - 1 ;
  for( ; x>=0; x--) {
      ans1[x] = '0'+(((ans1[x]-'0')+(sum[x]-'0')+carry)%10) ;
      carry = (((ans1[x]-'0')+(sum[x]-'0')+carry)/10) ;
  }
  ans[x] = '0'+((ans[x]-'0')+(sum[x]-'0')+carry) ;
  return ans1 ;
}

string multiply(string num1, string num2) {
  int n1 = num1.size() ;
  int n2 = num2.size() ;
  int carry = 0 ;
  string sum = "" ;
  string ans = "" ;
  for(int i=n1-1; i>=0; i--) {
      sum = "" ;
      for(int j=n2-1; j>=0; j--) {
          sum.push_back('0'+((((num1[i]-'0')*(num2[j]-'0'))+carry)%10)) ;
          carry = (((num1[i]-'0')*(num2[j]-'0'))+carry) / 10 ;
      }
      for(int j=i; j<(n1-1); j++) sum.push_back('0') ;
      ans = fsum(sum, ans) ;
  }
  return ans ;
}


int main() {
   sublimeInit() ;
   // read(x) ;
   // print(x) << endl ;
   // print("Kya Bhai log kaisa sab kuchh!") << endl ;
   // vector<int> arr({10, 9, 2, 5, 3, 7, 10, 18}) ;

   string ans = multiply("123", "123") ;
   cout << ans  << endl ;
   print(ans) << endl ;
   cout << "Are Maaki Chut!" << endl ;

   
   return 0 ;
}