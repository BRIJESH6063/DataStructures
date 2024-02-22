#include<bits/stdc++.h>
#include<iostream>
#include<Time.h>
using namespace std ;
#define ll long long
#define l  long
#define li long int 
#define d double
#define ld long double
#define read(x) int x ; cin >> x 
#define print(x) cout << x << " " 
#define readline(x) getline(cin, x) 

void sublimeInit() {
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin) ;
   freopen("output.txt", "w", stdout) ;
#endif
}

struct ListNode {
   int val;
   ListNode *next;
   ListNode() : val(0), next(nullptr) {}
   ListNode(int x) : val(x), next(nullptr) {}
   ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// // Linked List 
// LinkedList* reverseList(LinkedList* head) {
//    LinkedList* head1 = NULL ;
//    while(head) {
//       LinkedList* next1 = head->next ;
//       head->next = head1 ;
//       head1 = head ;
//       head = next1 ;
//    }
// }

// ListNode* reverseBetween(ListNode* head, int left, int right) {
//    ListNode* temp = head ;
//    ListNode* a = NULL ; ListNode* b = NULL ;
//    ListNode* c = NULL ; ListNode* d = NULL ;
//    ListNode* prev = NULL ;
//    while(temp) {
//       if(temp->val == left) {
//          a = prev ; c = temp ;
//       }  
//       if(temp->val == right) {
//          d = temp ; b = temp->right ;
//          break ;
//       }
//       prev = temp ;
//       temp = temp->next ;
//    }
//    if(c and d) {
//       temp = c ;
//       ListNode* head1 = NULL ;
//       while(temp != d) {
//          ListNode* next1 = temp->next ;
//          temp->next = head1 ;
//          head1 = temp ;
//          temp = next1 ;
//       }
//    }
//    if(!a) {
//       c->next = b ;
//       return d ;
//    }
//    else {
//       a->next = d ;
//       c->next = b ;
//       return head ;
//    }
// }


ListNode* remoneNthfromEnd(ListNode* head, int n) {
   ListNode* fast = head ;
   ListNode* slow = head ;
   ListNode* prev = NULL ;
   for(int i=0; i<n; i++) {
      fast = fast->next ;
   }
   while(fast) {
      fast = fast->next ;
      prev = slow ;
      slow = slow->next ;
   }
   if(prev == NULL) {
      prev = head ; head = head -> next ;
      prev = NULL ; delete(prev) ;
      return head ;
   }
   prev->next = slow->next ;
   prev = NULL ; slow = NULL ; fast = NULL ;
   delete(prev) ; delete(slow) ; delete(fast) ;
   return head ;

}


ListNode* remoneNthfromEndOpt(ListNode* head, int n) {
   ListNode* fast = head ;
   ListNode* slow = head ;
   ListNode* prev = NULL ;
   for(int i=0; i<n; i++) {
      fast = fast->next ;
   }
   while(fast) {
      fast = fast->next ;
      prev = slow ;
      slow = slow -> next ;
   }

   if(prev == NULL) {
      prev = head ; 
      head = head -> next ;
      prev = NULL ;
      delete(prev) ; return head ;
   }
   prev->next = slow->next ;
   prev = NULL ; slow = NULL ; 
   delete(prev) ; delete(fast) ; delete(slow) ;
   return head ;
}

// intersection point of two LinkedList
// one to one matching ===> [ m x n ] time complexity.. 
int f(ListNode* headA, ListNode* headB) {
   
}


class Node {
   public:
       int val;
       Node* prev; 
       Node* next;
       Node* child;
};

// flatten function defining ....
Node* mergeList(Node* a, Node* b) {
   Node* temp = new Node(0) ;
   Node* res = temp ;
   while(a && b) {
      if(a->data < b->data) {
         temp->bottom = a ;
         temp = temp->bottom ;
         a = a->bottom ;
      }
      else {
         temp->bottom = b ;
         temp = temp->bottom ;
         b = b->bottom ;
      }
   }
   if(a) temp->bottom = a ;
   else if(b) temp->bottom = b ;
   return res->bottom ;
}


// flattening a linked list...
ListNode* flatten(ListNode* root) {
   if(! root || ! root->next) return root ;
   root->next = flatten(root->next) ;
   root = mergeList(root, root->next) ;
   return root ;
}

int main() {
   sublimeInit() ;
   read(x) ; print(x) << endl ;
   print("Kya bat h kya chij h paisa!") << endl ;


   return 0 ;
}