// Given a substring, Print all those Permutation which does not contain "AB" as substring.

#include<bits/stdc++.h>
using namespace std ;

void swap(char &c1, char &c2){
    
}
void Permute(string str, int l, int r)
{
    if(l == r) {
        cout << str << endl ; return ;
    }
    else {
        for(int i=l; i<=r; i++){
            swap(str[l], str[i]) ;
            Permute(str, l+1, r)  ;
            swap(str[l], str[i]) ;
        }
    }
}


int main()
{
    string str = "ABC" ;

    Permute(str, 0, 2) ;
    return 0 ;
}