// Given an array of non-negative integers nums, you are initially positioned at the first index of the array.
// Each element in the array represents your maximum jump length at that position.
// Your goal is to reach the last index in the minimum number of jumps.
// You can assume that you can always reach the last index.

// Input: nums = [2,3,1,1,4]
// Output: 2
// Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.

// Input: nums = [2,3,0,1,4]
// Output: 2

int jump(vector<int>& nums) {
    int n=nums.size();
    int maxReach=0,currEnd=0,jumps=0;
    for(int i=0;i<n-1;i++){
        //store max reachable index currently
        maxReach = max(maxReach,nums[i]+i);
        //we have reached the end of jump
        if(currEnd == i){
            //take next jump
            jumps++;
            //next end will be max reachable index
            currEnd=maxReach;
        }
    }
    return jumps;
}
