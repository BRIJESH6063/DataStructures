#include<bits/stdc++.h>
using namespace std ;

bool comp(string s1, string s2) {
    return s1.size() < s2.size() ;
}

bool checkPossible(string &s1, string &s2) {
    if(s1.size() != s2.size()+1) return false ;
    int first = 0 ; 
    int second = 0 ;
    while(first < s1.size()) {
        if(s1[first] == s2[second]) {
            first ++ ; second ++ ;
        }
        else first ++ ;
    }
    if(first == s1.size() && second == s2.size()) return true ;
    else return false ;
}

int longStringChain(vector<string> words) {
    int n = words.size() ;
    sort(words.begin(), words.end(), comp) ;
    int maxi = 0 ;
    vector<int> dp(n, 1) ;
    for(int i=0; i<n; i++) {
        for(int j=0; j<i; j++) {
            if(checkPossible(words[i], words[j]) && dp[j]+1 > dp[i]) 
                dp[i] = 1 + dp[j] ;
        }
        maxi = max(maxi, dp[i]) ;
    }
    return maxi ;
}

int main()
{
    vector<string> words({"a", "b", "ba", "bca", "bdca", "c"}) ;
    cout << longStringChain(words) << endl ;

    return 0 ;
}