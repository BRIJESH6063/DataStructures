#include<bits/stdc++.h>
using namespace std ;

class Stack {
     private :
             int* arr ; int capacity ; int top ;
     public  :
             Stack(){
                 this->capacity = 5 ; top = -1 ;
                 arr = new int[capacity] ;
             }
             Stack(int capacity){
                 top = -1 ; this->capacity = capacity ;
                 arr = new int[capacity] ;
             }
             int size(){
                return (top+1) ;
             }
             void push(int data){
                if(top < capacity-1) {
                    top ++ ; arr[top] = data ;
                }
                else {
                    // cout << "Error! cannot insert data in the stack." << endl ;
                    capacity *= 2 ; 
                    int* newArr = new int[capacity] ;
                    for(int i=0; i<=top; i++) newArr[i] = arr[i] ;
                    delete [] arr ; arr = newArr ;
                    top ++ ; arr[top] = data ;
                }
             }

             bool isEmpty(){
                if(top == -1) return true ;
                else return false ;
             }
             int getTop(){
                return top ;
             }
             int* getArr(){
                return arr ;
             }

            int getCapacity(){
                return capacity ;
            }

            void pop(){
                top -- ;
            }
} ;