// Sieve Algorithm.. finding prime in optimised way 

#include <bits/stdc++.h>
using namespace std;

const int N = 1e7 + 10 ;
vector<bool> isPrime(N, 1) ;

int main() {
	isPrime[0] = isPrime[1] = false ;
	for(int i=2; i<N; i++){
	    if(isPrime[i] == true){
	        for(int j=i*2; j<N; j+=i){
	            isPrime[j] = false ;
	        }
	    }
	}
	
	for(int i=1; i<= 100; i++){
	    if(isPrime[i]) cout << i << " " ;
	}
	cout << endl ;
	int t ; cin >> t ;
	while(t--){
	    int n ; cin >> n ; 
	    if(isPrime[n]) cout << "prime" << endl ;
	    else cout << "not prime" << endl ;
	}
	
	return 0;
}


/* Time Complexicity 
   n ( 1 + 1/2 + 1/3 + 1/5 + 1/7 + 1/11 + 1/13 ..........)

   t(n) = n*log(log(n))
*/