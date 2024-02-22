// Binary exponentiation iterative method.. 

#include <bits/stdc++.h>
using namespace std;
const int M = 1e9+7 ;

int binExpIter(int a, int b)
{
    int ans = 1 ;
    while(b){
        if(b&1) ans = (ans*1LL*a)%M ;
        a = (a*1LL*a)%M ;
        b >>= 1 ;
    }
    return ans ;
}

int main() {
	int a ; int b ; cin >> a >> b ;
	cout << M*1LL << endl ;
	cout << binExpIter(a, b) << endl ;
	cout << pow(a,b)*1LL << endl ;
	return 0;
}

/*
input 13 30
output -- 
1000000007
133503566
2.62e+33


*/