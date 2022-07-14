// Given a circular integer array nums of length n, return the maximum possible sum of a non-empty subarray of nums.
// A circular array means the end of the array connects to the beginning of the array. 
// Formally, the next element of nums[i] is nums[(i + 1) % n] and the previous element of nums[i] is nums[(i - 1 + n) % n].
// A subarray may only include each element of the fixed buffer nums at most once. Formally, 
// for a subarray nums[i], nums[i + 1], ..., nums[j], there does not exist i <= k1, k2 <= j with k1 % n == k2 % n.

// Input: nums = [1,-2,3,-2]
// Output: 3
// Explanation: Subarray [3] has maximum sum 3.

// Input: nums = [5,-3,5]
// Output: 10
// Explanation: Subarray [5,5] has maximum sum 5 + 5 = 10.
  
// Input: nums = [-3,-2,-3]
// Output: -2
// Explanation: Subarray [-2] has maximum sum -2.


//we use kadanes algo but we use trick,
// 1. find max subarr sum using kadanes
// 2. find min subarr sum using kadanes
// 3. now circular sum = total - min subarr sum
// 4. so res = max( non circular subarr sum i.e. max sum, circular subarr sum)
// 5. edge case is when all arr elems are negative, then total - min sum == 0 as, minsum = total, so we return max sum in this case, which would be max elem in arr
int maxSubarraySumCircular(vector<int>& nums) {
    int noncircular=INT_MIN, minSum = INT_MAX, currPos = 0, currNeg=0;
    int total=0;
    for(auto &i: nums){
        total+=i;

        currPos = max(currPos+i, i);
        noncircular = max(currPos, noncircular);

        currNeg = min(currNeg+i, i);
        minSum = min(currNeg, minSum);
    }

    int circular = total - minSum;
    if(circular == 0) return noncircular;
    return max(noncircular, total - minSum);
}
