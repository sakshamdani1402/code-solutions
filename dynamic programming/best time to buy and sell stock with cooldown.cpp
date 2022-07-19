/* You are given an array prices where prices[i] is the price of a given stock on the ith day.
Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times) with the following restrictions:
After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).
Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

Input: prices = [1,2,3,0,2]
Output: 3
Explanation: transactions = [buy, sell, cooldown, buy, sell]

Input: prices = [1]
Output: 0 */

// METHOD 1 - DP (RECURSION + MEMO)
int func(vector<int>& prices,int i,bool canBuy,vector<vector<int>>&dp){
    if(i>=prices.size())  // If we reach the end of the vector, return 0 as no further profit can be made.
        return 0;
    if(dp[i][canBuy]!=-1){ //Value for this state is already calculated, so just return it.
        return dp[i][canBuy] ;
    }
    int x,y;
    if(canBuy==1){ // if we can buy, we have these two options. Return the maximum of these two
        x=func(prices,i+1,0,dp)-prices[i];  
        y=func(prices,i+1,1,dp);
        return dp[i][canBuy] = max(x,y);
    }
    else{// if we can sell, we have these two options. Return the maximum of these two.
        x=prices[i]+func(prices,i+2,1,dp);
        y=func(prices,i+1,0,dp);
        return dp[i][canBuy] = max(x,y);
    }
}

int maxProfit(vector<int>& prices) {
    int idx=0;
    int n = prices.size();
    vector<vector<int>>dp(n,vector<int>(2,-1));
    return func(prices,idx,1,dp); // Starting with index 0 call func with canBuy = 1.
}

//METHOD 2 - O(1) SPACE
int maxProfit(vector<int>& prices) {
 
    int buy=0, prevbuy=intmin, sell=0, prevsell=0, prev2sell=0;

    for(int &i: prices){
        buy = max(prev2sell-i, prevbuy);    // SELL + 1 DAY REST + BUY TODAY, REST 
        sell = max(prevbuy+i, prevsell);    // BOUGHT EARLIER + SELL TODAY, REST

        prevbuy=buy, prev2sell=prevsell, prevsell=sell; //UPDATE VARS
    }
    
    return sell;    //RETURN PROFIT BUY SELLING
}
