// m coloring problems ... 

#include<bits/stdc++.h>
using namespace std ;
#define V 4

bool isSafe(bool graph[V][V], int color[], int i, int j) {
    for(int k=0; k<V; k++) {
        if(graph[i][k] && color[k] == j) return false ; 
    }
    
    return true ;
}

bool graphColoringUtil(bool graph[V][V], int m, int color[], int i=0){
    if(i == V) return true ;
    
    for(int j =1; j<=m; j++) {
        if(isSafe(graph, color, i, j))  {
            color[i] = j ;
            if(graphColoringUtil(graph, m, color, i+1)) return true ;
            color[i] = 0 ;
        }
    }
    
    return false ;
}

void printColorSolution(int color[]) {
    for(int i=0; i<V; i++) cout << color[i] << "  " ;
    cout << endl ; 
}


bool graphColoring(bool graph[V][V], int m) {
    int color[V] = {0} ;
    if(graphColoringUtil(graph, m, color) == false ) {
        cout << "Solution doesn't exist .. " << endl ; 
        return false ;
    }
    
    printColorSolution(color) ; return true ;
    
}



int main()
{
    /* Create following graph and test
       whether it is 3 colorable
      (3)---(2)
       |   / |
       |  /  |
       | /   |
      (0)---(1)
    */
    bool graph[V][V] = {
        { 0, 1, 1, 1 },
        { 1, 0, 1, 0 },
        { 1, 1, 0, 1 },
        { 1, 0, 1, 0 },
    };  
    int m = 3; // total number of colors
    graphColoring(graph, m);
    
    
    return 0;
}