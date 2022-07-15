// Given an array of integers nums, find the maximum length of a subarray where the product of all its elements is positive.
// A subarray of an array is a consecutive sequence of zero or more values taken out of that array.
// Return the maximum length of a subarray with positive product.

// Input: nums = [1,-2,-3,4]
// Output: 4
// Explanation: The array nums already has a positive product of 24.

// Input: nums = [0,1,-2,-3,-4]
// Output: 3
// Explanation: The longest subarray with positive product is [1,-2,-3] which has a product of 6.
// Notice that we cannot include 0 in the subarray since that'll make the product 0 which is not positive.

// Input: nums = [-1,-2,-3,0,1]
// Output: 2
// Explanation: The longest subarray with positive product is [-1,-2] or [-2,-3].

//ALGO
// -- If we see a 0, we gotta start off things again
// -- If we see a positive number :
//      -- Increase length of positive multiplicative result till now.
//      -- Increase length of negative multiplicative result till now, if we have not encountered any negative before (neg count = 0).
// -- If we see a negative number:
//      -- It's time to swap positive and negative multiplicative results as neg*pos = neg and neg*neg = pos 
//         and increment both counts( if we have seen negative num before as neg*neg = pos and we are seeing a neg num so both counts increment).
//      -- if we are neg num for the 1st time then we swap but only increment neg cnt ( as neg count becomes +ve after swap)
// In each iteration, use the length of positive mutilpicative result to compute answer.

int getMaxLen(vector<int>& nums) {
    int positive=0, negative=0; //pos and neg num counter
    int len=0;  //result
    for(int &i : nums){
        if(i==0) positive=0, negative=0;  //start again
        
        else if(i>0){   
            positive++;
            if(negative!=0) negative++; //neg product can only increment if there is neg num in consideration
        }
        
        else{
            if(negative!=0){  //if we have seen a neg num before
                swap(positive, negative); //pos cnt becomes neg cnt and vice versa
                positive++, negative++;   //if prod was -ve it becomes +ve , -ve num count ++
            }
            else{
                swap(positive, negative); //if this is the 1st neg num, the positive prod cannot increase
                negative++;               //only neg prod len increases
            } 
        }
        len = max(len, positive); //update res if possible
    }
    return len;
}
