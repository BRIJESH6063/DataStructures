#include <bits/stdc++.h>
using namespace std;

// maximum rectangle in histogram
int maxAreaRectHist(vector<int> &height) {
    int n = height.size() ; cout << n << endl ;
    int leftSmaller[n] = {0} ; int rightSmaller[n] = {0} ;
    stack<int> st ; stack<int> stk ;
    for(int i=0; i<n; i++) {
        while(!st.empty() && height[st.top()] >= height[i]) {
            st.pop() ;
        }
        if(st.empty()) leftSmaller[i] = 0 ;
        else leftSmaller[i] = st.top()+1 ;
        st.push(i) ;
    }
    for(int i=n-1; i>= 0; i--) {
        while(!stk.empty() && height[stk.top()] >= height[i]) {
            stk.pop() ;
        }
        if(stk.empty()) rightSmaller[i] = n-1 ;
        else rightSmaller[i] = stk.top()-1 ;
        stk.push(i) ;
    }
    for(auto x : leftSmaller) cout << x << " " ;
    cout << endl ;
    for(auto x : rightSmaller) cout << x << " " ;
    cout << endl ;
    int maxi = 0 ;
    for(int i=0; i<n; i++) {
        maxi = max(maxi, height[i]*(rightSmaller[i]-leftSmaller[i]+1)) ;
    }
    return maxi ;
}

// Single Pass Solution ....
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


int main() {
    vector<int> arr({0, 9}) ;
	cout << maxAreaRect(arr) << endl  ;
	
	return 0 ;
}
