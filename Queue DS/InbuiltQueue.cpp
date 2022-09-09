#include<bits/stdc++.h>
using namespace std ;

void TakeInput(queue<int> &q){
    int data ; cin >> data ;
    while(data != -1){
        q.push(data) ;
        cin >> data ;
    }
}

void PrintQueue(queue<int> q){
    while(!q.empty()){
        cout << q.front() << " " ;
        q.pop() ;
    }
    cout << endl ;
}

void ReverseQ(queue<int> &q){
    stack<int> s ;
    while(!q.empty()){
        s.push(q.front()) ; q.pop() ;
    }
    while(!s.empty()){
        q.push(s.top()) ; s.pop() ;
    }
}
int main()
{
    queue<int> q  ;
    TakeInput(q)  ;
    cout << "Queue   : " ; PrintQueue(q) ;
    ReverseQ(q) ;
    cout << "Reverse : " ; PrintQueue(q) ;
    q.pop() ; q.push(24) ; q.pop() ; q.pop() ; q.pop() ; 
    PrintQueue(q) ;
    ReverseQ(q) ;
    cout << "Reverse : " ; PrintQueue(q) ;

    return 0 ;
}


/*
    input  -- 
    14 87 95 64 39 27 15 78 49 38 -1 41 47
    output --
    Queue   : 14 87 95 64 39 27 15 78 49 38 
    Reverse : 38 49 78 15 27 39 64 95 87 14 
    27 39 64 95 87 14 24
    Reverse : 24 14 87 95 64 39 27  
*/