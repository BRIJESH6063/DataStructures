// #include<bits/stdc++.h>
// using namespace std ;

// // G 30 Word Ladder ||
// // Given two distinct words start words and target words a list of denoting 
// // wordLit of uniquewords of equal length find the length of shortest 
// // transformation subsequence from start word to target word .. 

// // Logic -> Dont delete the word from wordSet unless all level of that word are poped from queue 
// // Non Optimal Solution 

// vector<vector<string>> findSequence(string startWord, string targetWord, vector<string> &wordList) {
//     unordered_set<string> st(wordList.begin(), wordList.end()) ;
//     queue<vector<string>> q ;
//     q.push({startWord}) ;
//     vector<string> usedOnLevel ;
//     int level = 0 ;
//     vector<vector<string>> ans ;
//     while(! q.empty()) {
//         vector<string> vec = q.front() ;
//         q.pop() ;
//         // erase all words that has been used in previous level of transformation .. 
//         if(vec.size() > level) {
//             level++ ;
//             for(auto it : usedOnLevel) {
//                 st.erase(it) ;
//             }
//             usedOnLevel.clear() ;
//         }
        
//         string word = vec.back() ;
//         if(word == targetWord) {
//             if(ans.size() == 0) ans.push_back(vec) ;
//             else if(ans[0].size() == vec.size()) ans.push_back(vec) ;
//         }
            
//         for(int i=0; i<word.size() ; i++) {
//             char original = word[i] ;
//             for(char ch = 'a'; ch <= 'z'; ch++) {
//                 word[i] = ch ;
//                 if(st.count(word) > 0 ) {
//                     vec.push_back(word) ;
//                     q.push(vec) ;
//                     // mark as visited on the level 
//                     usedOnLevel.push_back(word) ;
//                     vec.pop_back() ;
//                 }
//             }
//             word[i] = original ;
//         }
//     }
//     return ans ;
// }

// int main()
// {



//     return 0 ; 
// }

// Time complexity Doesnt support for Leetcode

#include<bits/stdc++.h>
using namespace std ;

// G 31 Word Ladder ||
// Given two distinct words start words and target words a list of denoting 
// wordLit of uniquewords of equal length find the length of shortest 
// transformation subsequence from start word to target word .. 

// Logic -> Dont delete the word from wordSet unless all level of that word are poped from queue 
// Optimal Solution for CP

unordered_map<string, int> mpp ;
vector<vector<int>> ans ;
string b ;

void dfs(string word, vector<string> &seq) {
    if(word == b ) {
        reverse(seq.begin(), seq.end()) ;
        ans.push_back(seq) ;
        reverse(seq.begin(), seq.end()) ;
        return ;
    }
    int steps = mpp[word] ;
    int sz = word.size() ;
    for(int i=0; i<seq.size(); i++) {
        char original = word[i] ;
        for(char ch = 'a' ; ch <= 'z'; ch ++) {
            word[i] = ch ;
            if(mpp.find(word) != mpp.end() && mpp[word] + 1 == steps) {
                seq.push_back(word) ;
                dfs(word, seq) ;
                
            } 
        }
        word[i] = original ;
    }
}

vector<vector<string>> findSequence(string startWord, string targetWord, vector<string> &wordList) {
    unordered_set<string> st(wordList.begin(), wordList.end()) ;
    queue<vector<string>> q ;
    b = startWord ;
    q.push({startWord}) ;
    mpp[startWord] = 1 ;
    int size = startWord.size() ;
    st.erase(startWord) ;
    while(! q.empty()) {
        string word = q.front() ;
        int steps = mpp[word] ;
        q.pop() ;
        if(word == targetWord) break ;
        for(int i=0; i<size; i++) {
            char original = word[i] ;
            for(char ch = 'a'; ch <= 'z'; ch++) {
                word[i] = ch ;
                if(st.count(word)) {
                    q.push(word) ;
                    st.erase(word) ;
                    mpp[word] = steps + 1 ;
                }
            }
            word[i] = original ;
        }
    }
    if(mpp.find(targetWord) != mpp.end()) {
        vector<string> seq ;
        seq.push_back(targetWord) ;
        dfs(targetWord, seq) ;
    }
    return ans ;
}




int main()
{



    return 0 ; 
}