#include<bits/stdc++.h>
using namespace std ;

// Single Pass Solution Max Rectangle Histogram....
int maxAreaRect(vector<int> &height) {
    int n = height.size() ;
    stack<int> st ;
    int maxA = 0 ;
    for(int i=0; i<=n; i++) {
        while(!st.empty() && (i == n || height[st.top()] >= height[i])) {
            int hgt = height[st.top()] ;
            st.pop() ;
            int width ;
            if(st.empty()) width = i ;
            else width = i - st.top()-1 ;
            maxA = max(maxA, (width*hgt)) ;
        }
        st.push(i) ;
    }
    return maxA ;
}

int maxRectSubMatrix(vector<vector<int>> &matrix) {
    int m = matrix.size() ;
    int n = matrix[0].size() ;
    vector<int> height(n, 0) ;
    int maxArea = 0 ;
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            if(matrix[i][j] == 1) height[j]++ ;
            else height[j] = 0 ;
        }
        int area = maxAreaRect(height) ;
        maxArea = max(area, maxArea) ;
    }
    return maxArea ;
}

int main()
{
    vector<vector<int>> matrix({{1, 0, 1, 0, 0},
                                {1, 0, 1, 1, 1},
                                {1, 1, 1, 1, 1},
                                {1, 0, 0, 1, 0}}) ;
    
    cout << maxRectSubMatrix(matrix) << endl ;
    return 0 ;
}