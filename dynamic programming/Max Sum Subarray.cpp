// Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.
// A subarray is a contiguous part of an array.

// Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
// Output: 6
// Explanation: [4,-1,2,1] has the largest sum = 6.

//SOLVED USING KADANE'S ALGO
int maxSubArray(vector<int>& nums) {
    int sum=0,maxSum=INT_MIN;
    for(auto &i: nums){
        sum+=i;
        maxSum=max(maxSum,sum); //update max sum found till now
        if(sum<0) sum=0;  //we need max sum, so if sum goes negative, we set it to zero for fresh calculation ahead
    }
    return maxSum;
}
