// Sieve Algorithm.. finding the Divisors.

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10 ;
vector<int> divisors[N] ;

int main() {
	
	for(int i=2; i<N; i++){
	    for(int j=i; j<N; j+=i) 
	    divisors[j].push_back(i) ;
	}
	
	for(int i=2; i<=10; i++){
	    cout << i << " : " ;
	    for(auto x : divisors[i])
	    cout << x << "  " ;
	    cout << endl ;
	}
	return 0;
}


/* Time Complexicity 
   n ( 1 + 1/2 + 1/3 + 1/5 + 1/7 + 1/11 + 1/13 ..........)
   t(n) = n*log(log(n))
   
 
   output ---
   2 : 2  
   3 : 3  
   4 : 2  4  
   5 : 5  
   6 : 2  3  6  
   7 : 7  
   8 : 2  4  8  
   9 : 3  9  
   10 : 2  5  10  

*/