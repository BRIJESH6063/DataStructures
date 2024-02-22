#include<bits/stdc++.h>
#include<iostream>
#include<Time.h>
using namespace std ;
#define ll long long
#define l  long
#define li long int 
#define d double
#define ld long double
#define read(x) int x ; cin >> x 
#define print(x) cout << x << " " 
#define readline(x) getline(cin, x) 

void sublimeInit() {
   #ifndef ONLINE_JUDGE
      freopen("input.txt", "r", stdin) ;
      freopen("output.txt", "w", stdout) ;
   #endif
}

int x = 100 ;

// class Base {
//    public :
//    Base() {
//       cout << "Base Constructor called!" << endl ;
//    }
//    void fun() {
//       cout << "base function called" << endl ;
//    }
//    virtual ~ Base() {
//       cout << "Virtual Base Destructor called!" << endl ;
//    }
// } ;
// class Child : public Base {
//    public :
//    Child() {
//       cout << "Child Constructor called!" << endl ;
//    }
//    void fun() {
//       cout << "child function called" << endl ;
//    }
//    void fun(int a) {
//       cout << "child function called arg: " << a << endl ;
//    }
//    ~ Child() {
//       cout << "Child Destructor called!" << endl ;
//    }
// } ;
// class Base {
//    public :
//    virtual void fun(int x=0) {
//       cout << "virtual base fun called with x : " << x << endl ;
//    }
// } ;

// class Child : public Base {
//    public :
//    void fun(int x) {
//       cout << "child fun called : " << x << endl ;
//    }
// } ;
// // virtual copy constructor
// class A {
//    int a ;
//    int b ;
//    public :
//    A(A &obj) {
//       this->a = a ;
//       this->b = b ;
//    }
// }


// class my_class {
//    private :
//    ~ my_class() {
//       cout << "destructor private never accessible called by friend function!" << endl ;
//    }
//    friend void destroy(my_class *a) ;
//    int x ;
//    public :
//    my_class(int x) {
//       this->x = x ;
//    }
//    int findX() {
//       return x ;
//    }
// } ;

// void destroy(my_class *a) {
//    delete a ;
// }

// class my_class {
//    private :
//    int x ;
//    my_class(int x) {
//       this->x = x ;
//       cout << "private constructor called!" << endl ;
//       cout << "object created successfully!" << endl ;
//    }
//    friend void create(my_class **a) ;
//    public :
//    int findX() { return x ; }
// } ;

// void create(my_class **a) {
//    int b ; cin >> b ;
//    *a = new my_class(b) ;
// }

// void create_arr(int **arr) {
//    *arr = (int*) calloc(5, sizeof(int)) ;
// }

// -------------------------------------------------------------->

// Code for Heap sort 

// void heapify(int arr[], int n, int i=0) {
//    int largest = i ;
//    int left = 2*i + 1 ; 
//    int right = 2*i + 2 ;
//    if(left < n && arr[left] > arr[largest]) largest = left ;
//    if(right < n && arr[right] > arr[largest]) largest = right ; 
//    if(largest != i) {
//       swap(arr[i], arr[largest]) ;
//       heapify(arr, n, largest) ;
//    }
// }


// void heapSort(int arr[], int n) {
//    // heapify with upper of leaf node
//    for(int i=n/2-1; i>=0; i--) {
//       heapify(arr, n, i) ;
//    }
//    // extract each element one by one
//    for(int i=n-1; i>=0; i--) {
//       swap(arr[i], arr[0]) ;
//       heapify(arr, i, 0) ;
//    }
// }

// class A {
//    public :
//    friend virtual void fun() ;
//    // {
//    //    cout << "Base class virtual function" << endl ;
//    // }
// } ;

// class B : public A {
//    public :
//    friend void fun() ;
// } ;

// void fun() {
//    cout << "friend function of derived class" << endl ;
// }

// ----------------------------------------------------------------------
   
   

   
   


  


   
   

































































































































































































































































int main() {
   sublimeInit() ;
   // unsigned int x = unsigned(1ll*(1 >> 31) - 1) ;
   // cout << x << endl ;
   // cout << INT_MAX << endl ;
   // cout << sizeof(int) << endl ;
   // cout << sizeof(unsigned int) << endl ;
   // cout << sizeof(long) << endl ;
   // cout << sizeof(long long) << endl ;
   // cout << sizeof(double) << endl ;
   // cout << sizeof(char) << endl ;
   // cout << sizeof(bool) << endl ;


   // int a = 34 ;
   // switch(a) {
   //    case 23 : cout << 23 << endl ;
   //    break ;
   //    case 34 : cout << 34 << endl ;
   //    break ;
   //    default :
   //    cout << "default" << endl ;
   // }
   // Advanced Pattern in CPP 
   
   // for(int i=1; i<=3; i++) {
   //    for(int j=1; j<10; j++) {
   //       if((i+j)%4 == 0 || (i==2 && j%4 == 0)) cout << "*" ;
   //       else cout << " " ;
   //    }
   //    cout << endl ;
   // }
   // 


   // Child b ;
   // cout << "------------------------" << endl ;
   // b.fun() ;
   // b.Base::fun() ;
   // cout << "------------------------" << endl ;
   
   // Base* b = new Child() ;
   // b->fun() ;


   // my_class *mc = new my_class(45);
   // cout << mc->findX() << endl ;
   // destroy(mc) ;
   // // delete mc ;
   // // free(mc) ;
   // // mc = NULL ;

   // my_class *obj ;
   // create(&obj) ;
   // cout << obj->findX() << endl ;
   // delete obj ;

   // int *arr ;
   // create_arr(&arr) ;
   // for(int i=0; i<5; i++) {
   //    cout << *(arr+i) << " ";
   // }

   // int x = 345 ;
   // cout << x << endl ;




   // int arr[] = {22, 8, 74, 59, 41, 34, 51} ;
   // int n = sizeof(arr)/sizeof(arr[0]) ;
   // heapify(arr, n) ;
   // for(int i=0; i<n; i++) cout << arr[i] << " " ;
   // cout << endl ;
   
   // heapSort(arr, n) ;
   // for(int i=0; i<n; i++) cout << arr[i] << " " ;
   // cout << endl ;

   


   // fun() ;
   // // lambda functions ...
   // auto fun = [](const int &a, const int &b) -> int {
   //    return a * b ;
   // } ;
   // cout << fun(4, 8) << endl ;




   // -----------------------------------------------------------
   // 21-10-2023

   // int num = 1231 ;
   // const int *ptr = &num ; // Data constant not pointer
   // cout << *ptr << endl ;
   // ptr++ ;
   // cout << *ptr << endl ; // Garbage value
   // // *ptr = 123498 ; // Doesn't work 


   // int num = 1231 ;
   // int *const ptr = &num ; // pointer constant data not
   // cout << *ptr << endl ;
   // *ptr = 1234132 ;
   // cout << *ptr << endl ;
   // // ptr++ ;              // doesn't work
   // // cout << *ptr << endl ;
 
   // -----------------------------------------------------------------
   // int i = 9 ;
   // const_cast<int&> (i) = 199 ; // Re initialising constant value in program
   // // i = 1234 ;
   // cout << i << endl ;


   // ------------------------------------------------------------------

   // 11:11:2023

   // void pointer 
   // void *ptr = NULL ;
   // int a = 44 ;
   // ptr = &a ;
   // cout << *((int*)ptr) << endl ;
   // long long arr[10] ;
   // long long sum = 0 ;
   // for(int i=0; i<10; i++) {
   //    cin >> arr[i] ;
   //    sum += arr[i] ;
   //    cout << arr[i] << endl ;
   // }

   // cout << sum/10 << endl ;




   


   
   





































































































































































































































































































































































































































































































































































































































































































   return 0 ;
}

