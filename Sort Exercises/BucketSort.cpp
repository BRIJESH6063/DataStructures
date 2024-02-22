#include<bits/stdc++.h>
using namespace std;

void display(float *array, int size) 
{
   for(int i = 0; i<size; i++) cout << array[i] << " ";
   cout << endl;
}
void bucketSort(float *array, int size)
{
   vector<float> bucket[size];
   for(int i = 0; i<size; i++) bucket[int(size*array[i])].push_back(array[i]);

   for(int i = 0; i<size; i++) sort(bucket[i].begin(), bucket[i].end());       

   int index = 0;
   for(int i = 0; i<size; i++) 
   {
      while(!bucket[i].empty())
      {
         array[index++] = *(bucket[i].begin());
         bucket[i].erase(bucket[i].begin());
      }
   }
}

int main() {
   int n ; cin >> n ;
   float arr[n] = {0} ;
   srand(time(0)) ;
   for(int i=0; i<n; i++) arr[i] = (rand()%10)*0.1 ;
   cout << "The initial array arrangement is - " << endl ;
   display(arr, n) ;
   time_t t = clock() ;
   bucketSort(arr, n) ;
   t = clock() - t ;
   double time_taken = (((double)t)/CLOCKS_PER_SEC)*1000000 ;
   cout << "Time : " << time_taken << "      m.s." << endl ;
   cout << "The final arrangement of array after Bucketsort - " << endl ;
   display(arr, n) ;

   return 0 ;
}