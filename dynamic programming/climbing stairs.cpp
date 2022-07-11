// You are climbing a staircase. It takes n steps to reach the top.
// Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

// Input: n = 2
// Output: 2
// Explanation: There are two ways to climb to the top.
// 1. 1 step + 1 step
// 2. 2 steps

//at every step we have 2 options, either to take 1 step or 2 steps from the current position, this way we can say this problem is a fibbonacci sequence
// func(n) = func(n-1) + func(n-2)

//METHOD 1: BOTTOM-UP DP
int solve(unordered_map<int,int>& dp,int n){
    if(dp.find(n)!=dp.end()) return dp[n];

    return dp[n] = solve(dp,n-1) + solve(dp,n-2);
}

int climbStairs(int n) {
    unordered_map<int,int> dp;
    dp[0]=0;
    dp[1]=1, dp[2]=2;
    return solve(dp,n);
}

//METHOD 2: OPTIMIZED FIBONACCI
int climbStairs(int n) {
    if(n<=0)    return 0;
    if(n==1)    return 1;
    if(n==2)    return 2;
    int twoStepsAway=1,oneStepAway=2,ways=0;
    for(int i=3;i<=n;i++){
        ways=twoStepsAway+oneStepAway;
        twoStepsAway=oneStepAway; 
        oneStepAway=ways;
    }
    return ways;
}
