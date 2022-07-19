/* An integer array is called arithmetic if it consists of at least three elements and if the difference between any two consecutive elements is the same.
For example, [1,3,5,7,9], [7,7,7,7], and [3,-1,-5,-9] are arithmetic sequences.
Given an integer array nums, return the number of arithmetic subarrays of nums.
A subarray is a contiguous subsequence of the array.

Input: nums = [1,2,3,4]
Output: 3
Explanation: We have 3 arithmetic slices in nums: [1, 2, 3], [2, 3, 4] and [1,2,3,4] itself.

Input: nums = [1]
Output: 0 */

/* idea is to iterate thru nums form 3rd elem (index : 2) and find all AP's
on curr index, AP's can be found by checking if last 3 elems have same common diff
eg:  [1,2,3,4]
starting from idx 2, we check the CD, now since 1,2,3 are in AP
update dp[2] to 1, since we have only 1 AP till now
now at idx 3
we see 2,3,4 are in AP as well, so total AP's found till now at curr idx is 1+ dp[2]
thus dp[3] = 2
total AP's is sum of all elem in DP i.e. dp[2]+dp[3] = 1+2 = 3 which is our ans */

int numberOfArithmeticSlices(vector<int>& nums) {
    int count=0, n=nums.size();
    //min 3 nos req so if input is smaller than 3 return 0
    if(n<=2) return count;
    //table
    vector<int> dp(n,0);
    
    //min 3 elem req so we start from 2nd index i.e. 3rd elem
    for(int i=2; i<n; i++){
        //if past 2 elem are in ap with curr elem
        if(nums[i]-nums[i-1] == nums[i-1] - nums[i-2]){
            
            /* update count in memo as no of AP's currently is
            no of all past AP's found till now+1 (for newly found AP at curr idx) */
            dp[i] += dp[i-1] +1;
            
            //total AP count is sum of all AP's found
            count+=dp[i];
        }
    }
    return count;
}
/* we can implement this in o(1) space just by maintaing a dp variable and increment it
while we are finding a new AP and reinit it to 0 as soon as we dont find an AP
to start freshly form upcoming index */
