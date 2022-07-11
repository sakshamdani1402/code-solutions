// There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). 
// The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.
// Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.

// Input: m = 3, n = 2
// Output: 3
// Explanation: From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
// 1. Right -> Down -> Down
// 2. Down -> Down -> Right
// 3. Down -> Right -> Down

int solve(vector<vector<int>>& dp,int m, int n){
    if(m<0 || n<0) return 0;  //if out of bounds return 0
    if(m==0 && n==0) return 1;  //if reach starting pos return 1

    if(dp[m][n]!=-1) return dp[m][n];   //if memoized, return val

    return dp[m][n] = solve(dp,m-1,n) + solve(dp,m,n-1);  //else move up or left from curr position and return it
}
int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m,vector<int>(n,-1));  //memo
    return solve(dp,m-1,n-1); //start from target
}
