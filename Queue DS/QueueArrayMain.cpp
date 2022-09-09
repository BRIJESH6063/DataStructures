#include<bits/stdc++.h>
#include"QueueArray.h"
using namespace std ;

int main()
{
    Queue<int> q(5) ;
    TakeInput(q)  ;
    PrintQueue(q) ;
    popData(q, 3) ;
    PrintQueue(q) ;


    return 0 ;
}


/*
  input -- 
  14 87 95 64 39 27 15 78 49 38 0 41
  output -- 
  87 95 64 39 27 15 78 49 38 
  39 27 15 78 49 38 
*/