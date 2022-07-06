// The stock span problem is a financial problem where we have a series of n daily price quotes for a stock and 
//we need to calculate the span of stocks price for all n days. 
// The span Si of the stocks price on a given day i is defined as the maximum number of consecutive days just before the given day, 
// for which the price of the stock on the current day is less than or equal to its price on the given day.
// For example, if an array of 7 days prices is given as {100, 80, 60, 70, 60, 75, 85}, then the span values for corresponding 7 days are {1, 1, 1, 2, 1, 4, 6}.

// Input: 
// N = 7, price[] = [100 80 60 70 60 75 85]
// Output:
// 1 1 1 2 1 4 6
// Explanation:
// Traversing the given input span for 100 
// will be 1, 80 is smaller than 100 so the 
// span is 1, 60 is smaller than 80 so the 
// span is 1, 70 is greater than 60 so the 
// span is 2 and so on. Hence the output will 
// be 1 1 1 2 1 4 6.

//since we need to find a day which has a price more than today, well maintain decreasing order of prices using a stack
vector <int> calculateSpan(int price[], int n){
       vector<int> res(n);
       res[0]=1;  //0th day cannot have any span bcz there is no prev elem
       stack<int> st; 
       st.push(0);  //push the 0th day
       //iterate from the 1st day
       for(int i=1;i<n;i++){  
           while(!st.empty() and price[st.top()]<=price[i]) st.pop(); //while price[top] is less than the price today
           
           if(st.empty()) res[i]=i+1; //if stack if empty that means there was no prev day which had price more than today, so span would be i+1
           else res[i]=i-st.top();    //else we have the idx of the day where the price was more than today
           
           st.push(i);  //push today for further consideration
       }
       return res;
}
