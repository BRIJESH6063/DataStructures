#include <bits/stdc++.h>
#include<time.h>
using namespace std;

void swap(int &x, int &y){
    int z = x ; x = y ; y = z ;
}
void bubbleSort(int *arr, int n)
{
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            if(arr[i] > arr[j]) swap(arr[i],arr[j]) ;
        }
    }
}

int main() {

    ios_base::sync_with_stdio(false); cin.tie(NULL) ;

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin) ;
	freopen("output.txt", "w", stdout) ;
	#endif 

	int n ; cin >> n ;
	int arr[n] = {0} ;
	srand(time(0));
      for(int i = 0; i<n; i++)
        arr[i] = rand()%100 ;
      time_t t = clock();
	for(int i=0; i<n; i++) cout << arr[i] << " " ;
	cout << endl ;
	bubbleSort(arr, n) ;
	t = clock() - t;
      double time_taken = ((double)t)/CLOCKS_PER_SEC;
      cout<<"TIME : "<<time_taken << endl ;
	for(int i=0; i<n; i++) cout << arr[i] << " " ;
	cout << endl ;
	return 0;
}
