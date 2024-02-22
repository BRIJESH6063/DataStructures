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

// string fsum(string &sum, string &ans) {
//   int x = sum.size() - ans.size() + 1 ;
//   string ans1 = "" ;
//   while(x--) ans1.push_back('0') ;
//   ans1.push_back('0') ;
//   x = ans.size() ;
//   while(x--) ans1.push_back(ans[ans.size()-x]) ;
//   int carry = 0 ;
//   x = sum.size() - 1 ;
//   for( ; x>=0; x--) {
//       ans1[x] = '0'+(((ans1[x]-'0')+(sum[x]-'0')+carry)%10) ;
//       carry = (((ans1[x]-'0')+(sum[x]-'0')+carry)/10) ;
//   }
//   ans[x] = '0'+((ans[x]-'0')+(sum[x]-'0')+carry) ;
//   return ans1 ;
// }

// string multiply(string num1, string num2) {
//   int n1 = num1.size() ;
//   int n2 = num2.size() ;
//   int carry = 0 ;
//   string sum = "" ;
//   string ans = "" ;
//   for(int i=n1-1; i>=0; i--) {
//       sum = "" ;
//       for(int j=n2-1; j>=0; j--) {
//           sum.push_back('0'+((((num1[i]-'0')*(num2[j]-'0'))+carry)%10)) ;
//           carry = (((num1[i]-'0')*(num2[j]-'0'))+carry) / 10 ;
//       }
//       for(int j=i; j<(n1-1); j++) sum.push_back('0') ;
//       ans = fsum(sum, ans) ;
//   }
//   return ans ;
// }


// // --------------------------------------------------------------------------
// // Topological Sorting BFS Kahn's Algorithm 
// vector<int> ToposortBFS(int V, vector<int> adj[]) {
//    vector<int> indegree(V, 0) ;
//    for(int i=0; i<V; i++) {
//       for(auto x : adj[i]) 
//          indegree[x]++ ;
//    }
//    vector<int> topo ;
//    queue<int> q ;
//    for(int i=0; i<V; i++) {
//       if(indegree[i] == 0)
//          q.push(i) ;
//    }

//    while(! q.empty()) {
//       int node = q.front() ;
//       topo.push_back(node) ;
//       q.pop() ;
//       for(auto x : adj[node]) {
//          indegree[x]-- ;
//          if(indegree[x] == 0) {
//             q.push(x) ;
//          }
//          cout << indegree[x] << " " ;
//       }
//    }
//    cout << endl ;
//    return topo ;
// }

// bool isPallindrome(string s, int i, int j) {
//   for(int a=i; a<=i+(j-1)/2; a++){
//       if(s[a] != s[i+j-i]) return false ;
//   }
//   return true ;
// }

// string longestPalindrome(string s) {
//   int n = s.size() ;
//   string ans = "" ;
//   for(int i=0; i<n; i++) {
//       for(int j=n-1; j>i; j--) {
//           cout << s.substr(i, j-i+1) << " : " << i << " " << j << endl ;
//           if(isPallindrome(s,i,j)) {
//               for(int a=i; a<=j; a++)
//               ans.push_back(s[a]) ;
//               return ans ;
//           }
//       }
//   }
//   ans.push_back(s[0]) ;
//   return ans ;
// }

// // ----------------------------------------------------------------
// int longestAwesome(string s) {
//   int n = s.size();
//   int mask = 0;
//   int ans = 0;
//   vector<int> dp(1024, n);
//   dp[0] = -1;
//   for(int i = 0; i < n; ++i){
//       mask ^= (1 << (s[i]-'0'));
//       cout << "mask : " << mask << " ans : " ;
//       ans = max(ans, i - dp[mask]);
//       for(int j = 0; j <= 9; ++j){
//           cout << ans << " " ;
//           ans = max(ans, i - dp[mask^(1<<j)]);
//       }
//       cout << endl ; 
//       if(dp[mask] == n) dp[mask] = i;
//   }
//   return ans;
// }


// // --------------------------------------------------------------------
// int wordladder(string startword, string targetword, vector<string> &wordlist) {
//    queue<pair<string, int>> q ;
//    unordered_set<string> st(wordlist.begin(), wordlist.end()) ;
//    st.erase(startword) ;
//    q.push({startword, 1}) ;
//    while(! q.empty()) {
//       string word = q.front().first ;
//       int steps = q.front().second ;
//       q.pop() ;
//       if(word == targetword) return steps ;
//       for(int i=0; i<word.size(); i++) {
//          char original = word[i] ;
//          for(char ch = 'a'; ch <= 'z'; ch++) {
//             word[i] == ch ;
//             if(st.find(word) == st.end()) {
//                st.erase(word) ;
//                q.push({word, steps +1}) ;
//             }
//          }
//          word[i] = original ;
//       }
//    }
//    return 0 ;
// }




// inline int fun(int x, int y) { // lambda function ... 
//    return x+y ;
// }



// vector<int> searchInTheArray(vector<int>& arr, vector<int>& queries, int n, int q) {
//    // Write Your code here
//    sort(arr.begin(), arr.end()) ;
//    vector<int> queries1(queries) ;
//    sort(queries1.begin(), queries1.end()) ;
//    int i=0; int j=0;
//    int sum = 0 ;
//    unordered_map<int, int> mpp ;
//    while(i < n && j < q) {
//       while(j < q && arr[i] > queries1[j]) {
//          mpp[queries1[j]] = sum ;
//          j++ ;
//       }
//       sum += arr[i] ;
//       i++ ;
//    }
//    while(j < q){
//       mpp[queries1[j]] = sum ;
//    }
//    for(auto x : mpp) {
//       cout << x.first << " " << x.second << endl ;
//    }
//    vector<int> ans ;
//    return ans ;
// }

// int countSubstrings(string &s) {
//    int n = s.size() ;
//    string temp = "" ;
//    int ans = 0 ;
//    for(int i=0; i<n; i++) {
//       if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' 
//          || s[i] == 'u') {
//          temp += s[i] ;
//       }
//       else {
//          cout << temp << endl ;
//          int x = temp.size() ;
//          ans += (x*(x+1))/2 ;
//          temp = "" ;
//       }
//    }
//    int x = temp.size() ;
//    if(x) ans += (x*(x+1))/2 ;
//    return ans ;
// }

 // void f(string *str) {
 //   str = new string("kabakchodih?") ;
 // }


// class A {
//    private :
//    int privaten ;
//    protected :
//    int protectedn ;
//    public :
//    A() {
//       privaten = 45 ;
//       protectedn = 5777 ;
//    }
//    friend class B ;
// } ;

// class B {
//    public :
//    void bajade(A &a) {
//       cout << a.privaten << endl ;
//       cout << a.protectedn << endl ;
//    }
// } ;



// class A {
//    public :
//    int num = 45 ;
//    virtual void fun() {
//       cout << "I am virtual class A function!" << endl ;
//    }
// } ;

// class B : public A {
//    public :
//    int num = 47 ;
//    void fun() {
//       cout << "I am normal class B function!" << endl ;
//    }
// } ;




























































































































































































































































int main() {
   sublimeInit() ;
   // cout << "Hello Duniya!" << endl ;
   // vector<int> adj[8] ;
   // adj[0] = {1} ;
   // adj[1] = {2} ;
   // adj[2] = {3, 4} ;
   // adj[3] = {4, 7} ;
   // adj[4] = {5} ;
   // adj[5] = {6} ;
   // adj[7] = {5} ;
   // adj[8] = {1, 9} ;
   // adj[9] = {10} ;
   // adj[10] = {8} ;
   // adj[11] = {9} ;
   // int V = 8 ;

   // vector<int> ans = ToposortBFS(V, adj) ;
   // for(auto x : ans) cout << x << " " ;
   //    cout << endl ;
   // string A = "fbrrb" ;

   // int n = A.size() ;
   //  int ans = n ;
   //  string temp = "" ;
   //  for(int i=0; i<n; i++) {
   //      temp += A[i] ;
        

   //      if(isPallindrome(temp) && temp.size() > 1){
   //       cout << temp << endl ;
   //       ans += temp.size()/2 ;
   //       temp = "" ;
   //       cout << "ans : " << ans << endl ;
   //      }
   //  }
    
   //  cout << ans << endl ;

   // vector<int> A({21, 32}) ;
   // sort(A.begin(), A.end(), comp) ;
   // reverse(A.begin(), A.end()) ;
   //  string ans = "" ;
   //  for(auto x : A) {
   //      string s = "" ;
   //      while(x){
   //          s.push_back('0'+(x%10)) ;
   //          x = x/10 ;
   //      }
   //      reverse(s.begin(), s.end()) ;
   //      ans += s ;
   //  }
   //  cout << ans ;
   // cout << "final : " << longestPalindrome("caba") << endl ;
   // if(isPallindrome("aba", 0, 1)) cout << "HAHA" << endl ;




   // -------------------------------------------------------------

   // void *pVoid ;
   // pVoid = (void*)0 ;
   // printf("%lu", sizeof(pVoid)) ;
   // return 0 ;
   



   // vector<string> wordlist({"hot", "hit" "dot", "log", "dog", "lot", "cog"}) ;
   // cout << wordladder("hit", "cog", wordlist) << endl ;
   // cout << fun(5, 6) << endl ;



   // ----------------------------------------------------------------------

   // unsigned int x = int(1ll*(1 >> 31) - 1) ;
   // cout << x << endl ;
   // cout << sizeof(int) << endl ;
   // cout << sizeof(unsigned int) << endl ;
   // cout << sizeof(long) << endl ;
   // cout << sizeof(long long) << endl ;
   // cout << sizeof(double) << endl ;
   // cout << sizeof(char) << endl ;
   // cout << sizeof(bool) << endl ;
   // cout << "Hello World" << endl ;

   // int t ;
   // cin >> t ;
   // while(t--) {
   //    string s ;
   //    cin >> s ;
   //    cout << countSubstrings(s) << endl ;
   // }

   
   // stack<int> st({1, 2, 3, 4}) ;
   // stack<int> st2; st2.swap(st) ;
   // while(!st2.empty()) {
   //    cout << st2.top() << " " ;
   //    st2.pop() ;
   // }


   // int x = 40  ;
   // if(!(x&1)) goto label1 ;
   // else goto label2 ;
   // label1 :
   // cout << "even number" << endl ;
   // return 0 ;
   // label2 :
   // cout << "odd number" << endl ;
   // return 0 ;
   // label3 :
   // cout << "kya madarchodai h?" << endl ;


   // vector<int> arr({5, 7, 3, 4, 2, 9, 0}) ;
   // sort(arr.begin(), arr.end(), [](int &a, int &b)-> bool {
   //    return a > b ;
   // }) ;
   // for(auto it : arr) cout << it << " " ;
   // cout << endl ;

   // void *ptr = NULL ;
   // int a = 78 ;
   // float b = 243.56 ;
   // ptr = &a ;
   // cout << *((int*)ptr) << endl ;
   // ptr = &b ;
   // cout << *((float*)ptr) << endl ;


   // A a ;
   // B b ;
   // b.bajade(a) ;
   // A* b = new B();
   // b->fun() ;
   // cout << b->num ;

   // --------------------------------------------------------------------


   

   
   
   


   
























































































































































































































































































































































































































   return 0 ;
}





