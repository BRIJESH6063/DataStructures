#include<bits/stdc++.h>
using namespace std ;

template<typename T, typename V> 
class Pair {
    private : T x ; V y ;
    public  : 
            void setX(T x){
                this->x = x ;
            }
            T getX(){
                return x ;
            }
            void setY(V y){
                this->y = y ;
            }
            V getY(){
                return y ;
            }

} ;

int main() {
    // Pair<int> p1 ;
    // p1.setX(23) ; p1.setY(58) ;
    // cout << p1.getX() << "    " << p1.getY() << endl ;
    // Pair<double> p2 ;
    // p2.setX(23.102) ; p2.setY(58.365) ;
    // cout << p2.getX() << "    " << p2.getY() << endl ;
    // Pair<char> p3 ;
    // p3.setX('a') ; p3.setY('d') ;
    // cout << p3.getX() << "    " << p3.getY() << endl ;
    // Pair<string> p4 ;
    // p4.setX("Hello") ; p4.setY("Brijesh") ;
    // cout << p4.getX() << "    " << p4.getY() << endl ;

    Pair<int, double> p1 ;
    p1.setX(1.732) ; p1.setY(1.732) ;
    cout << p1.getX() << "   " << p1.getY()  << endl ;

    // Use pair to behave like triplet without declaring a triplet.. 

    Pair<Pair<int, int>, int> p ;
    Pair<int, int> temp ; 
    temp.setX(22) ; temp.setY(48) ;
    p.setX(temp)  ; p.setY(47) ;
    cout << p.getX().getX() << " " << p.getX().getY() << " " << p.getY() << endl ;
    

    return 0 ;
}


/*
  Return 0 number, double, boolean, NULL, char all hence consider using Template returns.
  

*/