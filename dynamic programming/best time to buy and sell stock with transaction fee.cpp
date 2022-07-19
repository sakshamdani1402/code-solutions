/* You are given an array prices where prices[i] is the price of a given stock on the ith day, and an integer fee representing a transaction fee.
Find the maximum profit you can achieve. You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction.
Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

Input: prices = [1,3,2,8,4,9], fee = 2
Output: 8
Explanation: The maximum profit can be achieved by:
- Buying at prices[0] = 1
- Selling at prices[3] = 8
- Buying at prices[4] = 4
- Selling at prices[5] = 9
The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.

Input: prices = [1,3,7,5,10,3], fee = 3
Output: 6 */

int maxProfit(vector<int>& prices, int fee) {
    int buy=-prices[0], profit=0;   //there is no cooldown here, so we have to buy a stock in starting, profit is 0 as we havent sold anything

    for(int i=1; i<prices.size(); i++){                 //from the 2nd day
        //we can sell from 2nd day
        profit = max(buy + prices[i] - fee, profit);    // BUY PRICE + SELL PRICES - FEE , REST (DONT SELL NOW)  
        buy = max(profit - prices[i], buy);             // PROFIT - BUY PRICE, REST (DONT BUY)
    }

    return profit;  
}
