#include<bits/stdc++.h>
using namespace std ;

template<typename T>
class Node {
    public :
           T data ;
           Node<T>* next ;
           Node(T data){
             this->data = data ;
             next = NULL ;
           }
} ;

template<typename T>
class Queue {
    private :
             Node<T>* head ;
             Node<T>* tail ;
             int size ;
    public  :
            Queue () {
                head = NULL ; tail = NULL ;
                size = 0 ;
            }
            int getSize(){
                return size ;
            }
            bool isEmpty(){
                return (size==0) ;
            }
            void push(T data){
                Node<T>* node = new Node<T>(data) ;
                if(head == NULL && tail == NULL){
                    head = node ; 
                }
                else tail->next = node ; 
                tail = node ; size ++ ;
            }
            void pop() {
                Node<T>* temp = head ;
                if(isEmpty()) return ;
                head = head->next ; temp->next = NULL ;
                delete temp ; temp = NULL ;
                size -- ;
            }
            T front(){
                if(isEmpty()) return 0 ; 
                return head->data ;
            }
            Node<T>* getHead(){
                return head ;
            }
            Node<T>* getTail(){
                return tail ;
            }
} ;