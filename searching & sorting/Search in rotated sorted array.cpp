/* There is an integer array nums sorted in ascending order (with distinct values).
Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].
Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.
You must write an algorithm with O(log n) runtime complexity.

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1

Input: nums = [1], target = 0
Output: -1 */

int search(vector<int>& nums, int target) {
    int low = 0, high=size(nums)-1,mid;
    while(low<=high){
        mid = low + (high-low)/2;
        if(nums[mid]==target) return mid;
        //check if left half is sorted
        else if(nums[low]<=nums[mid]){
            //if target lies in LHS move left else right
            if(target>=nums[low] and target<nums[mid]) high=mid-1;
            else low=mid+1;
        } //RHS is sorted
        else{
            if(target<=nums[high] and target>nums[mid]) low = mid+1;    //if in range move right else left
            else high=mid-1;
        }
    }
    return -1;
}
