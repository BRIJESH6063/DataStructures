#include<bits/stdc++.h>
using namespace std ;

template<typename T> 
class Stack {
     private :
             T* arr ; int capacity ; int top ;
     public  :
             Stack(){
                 this->capacity = 5 ; top = -1 ;
                 arr = new T[capacity] ;
             }
             Stack(int capacity){
                 top = -1 ; this->capacity = capacity ;
                 arr = new T[capacity] ;
             }
             int size(){
                return (top+1) ;
             }
             void push(T data){
                if(top < capacity-1) {
                    top ++ ; arr[top] = data ;
                }
                else {
                    // cout << "Error! cannot insert data in the stack." << endl ;
                    capacity *= 2 ; 
                    T* newArr = new T[capacity] ;
                    for(int i=0; i<=top; i++) newArr[i] = arr[i] ;
                    delete [] arr ; arr = newArr ;
                    top ++ ; arr[top] = data ;
                }
             }

             bool isEmpty(){
                if(top == -1) return true ;
                else return false ;
             }
             T getTop(){
                if(top >= 0 && top < capacity) return top ;
                else return -1 ;
             }
             T* getArr(){
                return arr ;
             }

            int getCapacity(){
                return capacity ;
            }

            void pop(){
                if(top == -1) return ;
                else top -- ;
            }
} ;