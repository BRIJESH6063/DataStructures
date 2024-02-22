#include <bits/stdc++.h>
using namespace std;

double eps = 1e-6 ;


int main() {
	double x ; cin >> x ;
	int n ; cin >> n ;
	double low = 1 ; double high = x ; double mid ;
	while(high - low > eps){
	    mid = (high+low)/2 ;
	    if(pow(mid, n) < x) low = mid ;
	    else high = mid ;
	}
	
	cout << setprecision(10) << low << endl << high << endl ;
	cout << pow(x, 1.0/(n)) << endl ;
	
	return 0;
}