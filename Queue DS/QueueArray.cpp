// Dynamic Queue new queue with expanded size created when it is full

#include<bits/stdc++.h>
using namespace std ;

template<typename T>
class Queue {
    private :
             T *arr ;
             int nextIndex ;
             int firstIndex ;
             int size ;
             int capacity ;
    public  :
             Queue() {
                capacity = 5 ;
                T arr = new int[capacity] ;
                nextIndex = 0 ;
                firstIndex = -1 ;
                size = 0 ;
             }
             Queue(int cap){
                capacity = cap ;
                T* arr = new T[capacity] ;
                nextIndex = 0 ;
                firstIndex = -1 ;
                size = 0 ;
             }
             int getSize(){
                return size ;
             }
             bool isEmpty() {
                return (size==0) ;
             }
             void push(T data){
                if(size == capacity) {
                    T* newArr = new T[capacity*2] ; int j = 0 ;
                    for(int i=firstIndex; i<capacity; i++){
                        newArr[j] = arr[i] ; j++ ;
                    }
                    for(int i=0; i<firstIndex; i++){
                        newArr[j] = arr[i] ; j++ ;
                    }
                    firstIndex = 0 ; nextIndex = capacity ;
                    capacity *= 2 ; delete [] arr ;
                    arr = newArr ;

                }
                arr[nextIndex] = data ;
                nextIndex = (nextIndex+1)%capacity ;
                if(firstIndex == -1) firstIndex = 1 ;
                size ++ ;
             }
             T front(){
                if(isEmpty()) {
                    cout << "Queue is empty.." << endl ;
                    return 0 ;
                }
                else return arr[firstIndex] ;
             }

             void pop(){
                if(isEmpty()) {
                    cout << "Queue is already empty.." << endl ;
                    return ;
                }
                firstIndex = (firstIndex+1)%capacity ; 
                size-- ;
                if(size == 0) {
                    // reset variables .. truly optional 
                    firstIndex = -1 ;
                    nextIndex = 0 ;
                }
            }
            T* getArr(){
                return arr ;
            }
            int getFirstIndex(){
                return firstIndex ;
            }
            int getNextIndex(){
                return nextIndex ;
            }
            int getCapacity(){
                return capacity ;
            }
} ;