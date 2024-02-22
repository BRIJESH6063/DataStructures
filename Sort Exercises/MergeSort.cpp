#include<bits/stdc++.h>
#include<time.h>
using namespace std;

void swapping(int &a, int &b) {     
   int temp;
   temp = a;
   a = b;
   b = temp;    }

void display(int *array, int size) {
   for(int i = 0; i<size; i++) cout << array[i] << " ";
   cout << endl;  }

void merge(int *array, int l, int m, int r) {
   int i, j, k, nl, nr;
   nl = m-l+1; nr = r-m;
   int larr[nl], rarr[nr];
   for(i = 0; i<nl; i++)
      larr[i] = array[l+i];
   for(j = 0; j<nr; j++)
      rarr[j] = array[m+1+j];
   i = 0; j = 0; k = l;
   while(i < nl && j<nr) {
      if(larr[i] <= rarr[j]) {
         array[k] = larr[i];
         i++;
      }else{
         array[k] = rarr[j];
         j++;      }
      k++;
   }
   while(i<nl) {       
      array[k] = larr[i];
      i++; k++;
   }
   while(j<nr) {     //extra element in right array
      array[k] = rarr[j];
      j++; k++;
   }
}

void mergeSort(int *array, int l, int r) {
   int m;
   if(l < r) {
      int m = l+(r-l)/2;
      // Sort first and second arrays
      mergeSort(array, l, m);
      mergeSort(array, m+1, r);
      merge(array, l, m, r);
   }
}

int main() {

   ios_base::sync_with_stdio(false); cin.tie(NULL) ;

   #ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin) ;
   freopen("output.txt", "w", stdout) ;
   #endif 

   int n; cin >> n ;
   int arr[n];     
   srand(time(0));
   for(int i = 0; i<n; i++) arr[i] = rand()%100 ;
   display(arr, n);
   time_t t = clock();
   mergeSort(arr, 0, n-1);     
   t = clock() - t;
   double time_taken = ((double)t)/CLOCKS_PER_SEC;
   cout<<"TIME : "<<time_taken << endl ;
   display(arr, n);
   return 0 ;
}