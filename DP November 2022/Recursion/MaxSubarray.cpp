// Given an integer array nums, find the contiguous subarray (containing at least
// one number) which has the largest sum and return its sum

#include<bits/stdc++.h>
using namespace std ;

int maxSubArray(vector<int> nums) {
    int n = nums.size() ; int maxSum = 0 ;
    for(int i=1; i<n; i++) {
        if(nums[i-1] > 0) nums[i] += nums[i-1] ;
        maxSum = max(maxSum, nums[i]) ;
    }

    for(int i=0; i<n; i++) cout << nums[i] << " " ;
    cout << endl ;

    return maxSum ;
}

int main() 
{
    vector<int> nums({-2,1,-3,4,-1,2,1,-5,4}) ;
    cout << maxSubArray(nums) << endl ;



    
    return 0 ;
}