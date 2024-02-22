#include<bits/stdc++.h>
#include<Time.h>
using namespace std ;
#if 0
#define x 3
#if x == 0
#define FUN() cout << "Called The Macros Function." << endl 
#else 
#define FUN()
#endif
#define hello cout << "Hello World 88 " << endl 
#define MAIN main() {\
   cout << "MAIN called by macros.." << endl ;\
}
// goes on console not output.txt 
// #include <> makes compiler to search source in special libraries defined by the creater.
// #include "" makes compiler to search source in the user created file folders for quick search.
// #endif


void sublimeInit() {
   #ifndef ONLINE_JUDGE
      freopen("input.txt", "r", stdin) ;
      freopen("output.txt", "w", stdout) ;
   #endif
}

int main() {
   sublimeInit() ;
   // hello ;
   // FUN() ;


   return 0;
}

// MAIN ;

