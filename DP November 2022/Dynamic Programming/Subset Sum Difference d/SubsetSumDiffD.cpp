#include<bits/stdc++.h>
using namespace std ;

int mod = (int)(1e9 + 7) ;
int countSubsetSumK(vector<int> &nums, vector<vector<int>> &dp, int s, int i) {
    // if(s == 0) return 1 ;
    // if(i == 0 ) return (nums[0] == s) ;
    if(i == 0) { 
        if(s == 0 && nums[0] == 0) return 2 ;
        else if(s == 0 || s == nums[i]) return 1 ;
        return 0 ;
    }
    if(dp[i][s] != -1) return dp[i][s] ;
    int notPick = countSubsetSumK(nums, dp, s, i-1) ;
    int pick = 0 ;
    if(nums[i] <= s) pick = countSubsetSumK(nums, dp, s-nums[i], i-1) ;
    return dp[i][s] = (pick + notPick)%mod ; 
}

int findWays(vector<int> &nums, int d) {
    int s = 0 ; int n = nums.size() ;
    for(auto x : nums) s += x ;
    vector<vector<int>> dp(n, vector<int>(s+1, -1)) ;
    if(s - d < 0 || (s - d) % 2) return 0 ;
    return countSubsetSumK(nums, dp, (s-d)/2, n-1);
}

int main()
{
    vector<int> nums({1, 0, 8, 5, 1, 4}) ;
    int d = 17 ;
    cout << findWays(nums, d) << endl ;

    return 0 ;
}