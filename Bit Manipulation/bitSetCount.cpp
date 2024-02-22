#include <bits/stdc++.h>
using namespace std;

void printBinary(int n)
{
    string s = "" ;
	for(int i=9; i>=0; i--){
	    s = s + to_string(1&(n>>i)) ;
	}
	cout << s << "    ";
	cout << "total set bits : " << count(s.begin(), s.end(),'1') ;
	cout << "     " << __builtin_popcount(n) ;
}

int main() {
	
	int n ; cin >> n ;
	
	int a ;
	printBinary(n) ; cout << endl ;
	a = n & (1<<1) ;
	printBinary(a) ; cout << endl ;
	a = n & (~(1<<2)) ;
	printBinary(a) ; cout << endl ;

	cout << __builtin_popcountll((1ll<<35)-1) << endl ;
	return 0;
}