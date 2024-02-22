#include<bits/stdc++.h>
#include<time.h>
using namespace std;

void display(int *array, int size) {
   for(int i = 0; i<size; i++)  cout << array[i] << " ";
   cout << endl;
}

void insertionSort(int *array, int size) {
   int key, j;
   for(int i = 1; i<size; i++) {
      key = array[i]; j = i;
      while(j > 0 && array[j-1]>key) {
         array[j] = array[j-1];
         j--;   }
      array[j] = key;    }
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
   for(int i = 0; i<n; i++)  arr[i] = rand()%100 ;
   display(arr, n);
   time_t t = clock();
   insertionSort(arr, n);
   t = clock() - t;
   double time_taken = ((double)t)/CLOCKS_PER_SEC ;
   cout<<"TIME : "<<time_taken << endl ;
   display(arr, n);
   return 0 ;   
}
