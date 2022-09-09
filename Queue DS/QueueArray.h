#include<bits/stdc++.h>
#include"QueueArray.cpp"
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
    T* temp = q.getArr() ; int first = q.getFirstIndex() ;
    int next = q.getNextIndex() ; int cap = q.getCapacity() ;
    for(int i= first ; i<next ; i = (i+1)%cap) cout << temp[i] << " " ;
    cout << endl ;
}

template<typename T>
void popData(Queue<T> &q, int d){
    for(int i=0; i<d; i++) q.pop() ;
    
}