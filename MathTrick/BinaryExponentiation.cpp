// Binary Exponentiation --> pow(a,b) works on approximation.


#include <bits/stdc++.h>
using namespace std;

long long int binaryExponent(int a, int b)
{
    if(b==0) return 1 ;
    long long res = binaryExponent(a,b/2) ;
    if(b%2) return a*res*res ; 
    else return res*res ;
}
int main() {
	int a ; int b ; cin >> a >> b ;
	cout << binaryExponent(a, b) << endl ;
	cout << long(pow(a, b)) << endl ;
	
	return 0;
}

