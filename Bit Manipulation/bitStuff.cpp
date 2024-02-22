#include<bits/stdc++.h>
#include<string.h>
using namespace std ;

string bitStuff(string s)
{
    int l = s.size() ; int count1 = 0 ; int StuffCount = 0 ;
    for(int i=0; i<l; i++){
        if(count1 == 5) {
            string s2 = s.substr(0,i) + "0" + s.substr(i, l) ;
            s = s2 ;
            count1 = 0 ; StuffCount ++ ;
        }
        else if(s[i] == '1') count1 ++ ;
        else count1 = 0 ;

    }
    cout << "After " << StuffCount << " bit stuffing " ;
    return s ;
}

string bitDestuff(string s)
{
    int l = s.size() ; int count1 = 0 ; int DestuffCount = 0 ;

    for(int i=0; i<l; i++){
        if(count1 == 5 and s[i] == '0'){

            string s2 = s.substr(0,i) + s.substr(i+1, l) ;
            s = s2 ;
            count1 = 0 ; DestuffCount ++ ;
        }
        else if(s[i] == '1') count1++ ;
        else count1 = 0 ;

    }

    cout << "After " << DestuffCount << " bit Destuffing " ;
    return s ;
}


int main()
{
    string bits ; cout << "input data Bits : "  ; cin >> bits ;
    cout << "original bits - " << bits << endl ;

    string Stuff = bitStuff(bits) ;
    cout << " Stuffing  bits of input binary data - " ;
    cout << Stuff << endl ;
    cout << "-------------------------------------------------------------" << endl ;
    string Destuff = bitDestuff(Stuff) ;
    cout << " Destuffing bits of Stuffed input binary data - " ;
    cout << Destuff << endl ;

    return 0 ;
}