// Sieve Algorithm.. finding highest and lowest prime in optimised way 

#include <bits/stdc++.h>
using namespace std;

const int N = 1e7 + 10 ;
vector<bool> isPrime(N, 1) ;
vector<int> high(N, 0) , low(N, 0) ;

int main() {
	isPrime[0] = isPrime[1] = false ;
	for(int i=2; i<N; i++){
		
	    if(isPrime[i] == true){
			high[i] = low[i] = i ;
	        for(int j=i*2; j<N; j+=i){
	            isPrime[j] = false ;
				high[j] = i ;
				if(!low[j]) low[j] = i ;
	        }
			
	    }
	}
	
	for(int i=1; i<= 100; i++){
	    cout << i << " " << low[i] << " " << high[i] << endl ;
	}
	int n ; cin >> n ; vector<int> prime_factors ; 
	while(n>1){
	    int prime_factor = high[n] ;
	    while(n%prime_factor == 0){
	        n /= prime_factor ;
	        prime_factors.push_back(prime_factor) ;
	        
	    }
	}
	
	for(auto x : prime_factors) cout << x << "  " ;
	cout << endl ;
	return 0;
}


/* Time Complexicity 
   n ( 1 + 1/2 + 1/3 + 1/5 + 1/7 + 1/11 + 1/13 ..........)

   t(n) = n*log(log(n))
*/