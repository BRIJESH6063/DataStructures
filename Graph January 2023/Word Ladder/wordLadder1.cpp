#include<bits/stdc++.h>
using namespace std ;

// G 29 Word Ladder 
// Given two distinct words start words and target words a list of denoting 
// wordLit of uniquewords of equal length find the length of shortest 
// transformation subsequence from start word to target word .. 
int wordLadderLength(string startWord, string targetWord, vector<string> &wordList) {
    queue<pair<string, int>> q ;
    q.push({startWord, 1}) ;
    unordered_set<string> st(wordList.begin(), wordList.end()) ;
    st.erase(startWord) ;
    while(! q.empty()) {
        string word = q.front().first ;
        int steps = q.front().second ;
        q.pop() ;
        if(word == targetWord) return steps ;
        for(int i=0; i<word.size(); i++) {
            char original = word[i] ;
            for(char ch = 'a' ; ch <= 'z'; ch ++) {
                word[i] = ch ;
                if(st.find(word) != st.end()) {
                    st.erase(word) ;
                    q.push({word, steps+1}) ;
                }
            }
            word[i] = original ;
        }
    }
    return 0 ;
}

int main()
{



    return 0 ; 
}