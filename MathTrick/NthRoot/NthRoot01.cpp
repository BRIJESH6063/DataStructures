#include <bits/stdc++.h>
using namespace std;

double eps = 1e-6 ;

int main() {
	double x ; cin >> x ;
	double low = 1 ; double high = x ; double mid ;
	while(high - low > eps){
	    mid = (high+low)/2 ;
	    if(mid*mid < x) low = mid ;
	    else high = mid ;
	}
	
	cout << setprecision(10) << low << endl << high << endl ;
	cout << pow(x, 1.0/2) << endl ;
	
	return 0;
}


/* ---------------------

input -- 3
output --
1.732049942
1.732050896
1.732050808

*/