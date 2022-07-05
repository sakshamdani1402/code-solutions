//Given an array(0-based indexing), you have to find the max sum of i*A[i] where A[i] is the element at index i in the array. 
//The only operation allowed is to rotate(clock-wise or counter clock-wise) the array any number of times.
// Input:
// N = 4
// A[] = {8,3,1,2}
// Output: 29
// Explanation: Above the configuration
// possible by rotating elements are
// 3 1 2 8 here sum is 3*0+1*1+2*2+8*3 = 29
// 1 2 8 3 here sum is 1*0+2*1+8*2+3*3 = 27
// 2 8 3 1 here sum is 2*0+8*1+3*2+1*3 = 17
// 8 3 1 2 here sum is 8*0+3*1+1*2+2*3 = 11
// Here the max sum is 29 

int max_sum(int A[],int N){
    int sum=0;
    for(int i=0;i<N;i++) sum+=A[i];
    
    int val=0;
    for(int i=0;i<N;i++) val+=(A[i]*i);
    
    int res = val;
    for(int i=1; i<N; i++){
        int nextVal = val- (sum-A[i-1]) + A[i-1]*(N-1);
        
        res=max(res,nextVal);
        val=nextVal;
    }
    
    return res;
}

//basic idea here is to find the val of the window from the curr idx (val = sum(i*A[i))
//store res=val as this is the default rotation we are given
//then we will start from the i=1, ie. elem at idx 1 will be the 0th elem and curr 0th elem will be rotated to the last idx i.e. N-1th idx
//The idea is to compute the value of a rotation using values of previous rotation. When an array is rotated by one, following changes happen in sum of i*arr[i]. 
//  1- Multiplier of arr[i-1] changes from 0 to n-1, i.e., arr[i-1] * (n-1) is added to current value.
//  2- Multipliers of other terms is decremented by 1. i.e., (cum_sum - arr[i-1]) is subtracted from current value where cum_sum is sum of all numbers.
// currsum - A[i-1] removes the i-1th elem from the window, now when we subtract this from val we get the sum of products of the curr window when 
//their idx are decremented by one 
//now since the i-th elem is rotated to the last position we add its multiplier arr[i-1] * (n-1) to the new val we got
//now we have the product of the curr rotation, we update res if nescessary and set the curr val as the new val we found for next rotation
