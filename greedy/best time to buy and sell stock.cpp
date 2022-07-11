// You are given an array prices where prices[i] is the price of a given stock on the ith day.
// You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
// Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

// Input: prices = [7,1,5,3,6,4]
// Output: 5
// Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
// Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.

//we get max profit when we buy stock at low price and sell at high price, i.e. profit is max (profit = stock price - cost price)
int maxProfit(vector<int>& prices) {
    int minCost=INT_MAX, maxProfit=0;
    for(auto &i: prices){
        minCost = min(minCost,i);   //min cost to buy the stock
        maxProfit = max(maxProfit, i-minCost);  //maximize profit
    }
    return maxProfit;
}
