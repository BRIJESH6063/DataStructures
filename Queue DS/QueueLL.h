#include<bits/stdc++.h>
#include"QueueLL.cpp"
using namespace std ;

template<typename T>
void TakeInput(Queue<T> &q){
    T data ; cin >> data ;
    while(data != 0){
        q.push(data) ;
        cin >> data ;
    }
}

template<typename T>
void PrintQueue(Queue<T> q){
    Node<T>* start = q.getHead() ; Node<T>* end = q.getTail() ;
    while(start){
        cout << start->data << "  " ;
        start = start->next ; 
    }
    cout << endl ;
}

template<typename T>
void popData(Queue<T> &q, int d){
    for(int i=0; i<d; i++) q.pop() ;
}