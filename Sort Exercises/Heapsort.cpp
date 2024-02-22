#include<bits/stdc++.h>
using namespace std ;

void heapify(int arr[], int n, int i)
{
    int largest = i ;
    int l = 2*i + 1 ;
    int r = 2*i + 2 ;

    if(l < n and arr[l] > arr[largest]) largest = l ;
    if(r < n and arr[r] > arr[largest]) largest = r ;

    if(largest != i)
    {
        swap(arr[i], arr[largest]) ;
        heapify(arr, n, largest)  ;
    }
}

void Heapsort(int arr[], int n)
{
    for(int i=(n/2)-1 ; i>=0; i--) heapify(arr, n, i) ;
    for(int i = n-1; i>= 0; i--)
    {
        swap(arr[0], arr[i]) ;
        heapify(arr, i, 0) ;
    }
}

void printArray(int arr[], int n)
{
    for(int i=0; i<n; ++i) cout << arr[i] << " " ;
    cout << endl ;
}

int main()
{
    int n ; cin >> n ;
    int arr[n] = {0} ;
    srand(time(0)) ;
    for(int i=0; i<n; i++) arr[i] = rand()%100 ;
    cout << "The initial array arrangement is - " << endl ;
    printArray(arr, n) ;
    time_t t = clock() ;
    Heapsort(arr, n) ;
    t = clock() - t ;
    double time_taken = (((double)t)/CLOCKS_PER_SEC)*1000000 ;
    cout << "Time : " << time_taken << "      m.s." << endl ;
    cout << "The final arrangement of array after Heapsort - " << endl ;
    printArray(arr, n) ;

    return 0 ;
}