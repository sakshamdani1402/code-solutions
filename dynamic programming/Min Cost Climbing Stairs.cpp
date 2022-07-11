// You are given an integer array cost where cost[i] is the cost of ith step on a staircase. Once you pay the cost, you can either climb one or two steps.
// You can either start from the step with index 0, or the step with index 1.
// Return the minimum cost to reach the top of the floor.

// Input: cost = [1,100,1,1,1,100,1,1,100,1]
// Output: 6
// Explanation: You will start at index 0.
// - Pay 1 and climb two steps to reach index 2.
// - Pay 1 and climb two steps to reach index 4.
// - Pay 1 and climb two steps to reach index 6.
// - Pay 1 and climb one step to reach index 7.
// - Pay 1 and climb two steps to reach index 9.
// - Pay 1 and climb one step to reach the top.
// The total cost is 6.

//we need min cost of climbing stairs, we have 2 moves, either take 1 step or 2 steps at a time
//so from the the relation becomes total cost(n) = cost(n) + min(cost(n-1), cost((n-2))
int minCostClimbingStairs(vector<int>& cost) {
    int n=cost.size();
    vector<int> dp(n);
    dp[0] = cost[0], dp[1]=cost[1]; //base cases

    for(int i=2;i<n;i++){
        dp[i] = cost[i]+ min(dp[i-1],dp[i-2]); 
    }

    return min(dp[n-1],dp[n-2]); //at the last floor, min cost can be from n-1 floor or n-2th floor
}

//RECURSIVE METHOD - TLE
 int len;
int solve(vector<int>& cost, int idx){
    //base cases
    if(idx<0) return 0; 
    if(idx==0 || idx==1) return cost[idx];
    //curr cost = cost of curr idx + min cost from n-1th or n-2th step
    return cost[idx] + min(solve(cost,idx-1), solve(cost,idx-2));
}
int minCostClimbingStairs(vector<int>& cost) {

    len=cost.size();
    return min(solve(cost,len-1),solve(cost,len-2));
}
