// long Binary exponentiation iterative method.. 

#include <bits/stdc++.h>
using namespace std;
const long long M = 1e18+7 ;

// enable multiplication to take place above 1e9 


long long binMultiply(long long a, long long b)
{
    long long ans = 0 ;
    while(b){
        if(b&1) ans = (ans+a)%M ;
        a = (a+a)%M ;
        b >>= 1 ;
    }
    return ans ;
}

long long binExpIter(long long a, long long b)
{
    long long  ans = 1 ;
    while(b){
        if(b&1) ans = binMultiply(ans,a) ;
        a = binMultiply(a,a) ;
        b >>= 1 ;
    }
    return ans ;
}


int main() {
	long long a ; long long b ; cin >> a >> b ;
	cout << M*1LL << endl ;
	cout << binExpIter(a, b) << endl ;
	//cout << 1LL*pow(a,b) << endl ;
	return 0;
}