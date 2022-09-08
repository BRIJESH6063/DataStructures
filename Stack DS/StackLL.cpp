#include<bits/stdc++.h>
using namespace std ;

template<typename T> 
class Node {
    private : T data ; Node* next ;
    public  : 
              Node(T data){
                   this->data = data ;
                   next = NULL ;
              }    
} ;
template<typename T>
class StackLL{
    private : Node<T>* head ;
              int size ;
    public :
             StackLL(){
                head = NULL ; size = 0 ;
             }
             int getSize(){
                return size ;
             }
             bool isEmpty(){
                if(size <= 0) return true ;
                else return false ;
             }
             void push(T data){
                Node<T>* node = new Node<T>(data) ;
                if(head == NULL) head = node ;
                else head->next = node ;
                head = node ; size ++ ;
             }
             void pop(){
                if(isEmpty()) return ;
                Node<T>* temp = head ; head = head->next ;
                delete(temp) ; temp = NULL ;
                size -- ;

             }
             T top(){
                if(isEmpty()) return 0 ;
                return head ;
             }
} ;