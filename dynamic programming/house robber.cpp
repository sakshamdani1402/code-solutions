// You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.
// Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

// Input: nums = [1,2,3,1]
// Output: 4
// Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
// Total amount you can rob = 1 + 3 = 4.

//METHOD 1 - DP {TOP-DOWN}
vector<int> dp;
int solve(vector<int>& nums, int n){
	if(n<0) return 0;	//if out of bounds
	if(dp[n]!=-1) return dp[n];	//if memoized

	return dp[n]= max(nums[n]+solve(nums,n-2), solve(nums,n-1));	//rob curr + rob n-2th or rob adj house not this 1
}
int rob(vector<int>& nums) {
	int n = nums.size();
	dp.resize(n,-1);

	return solve(nums,n-1);
}

//METHOD 2 - O(1) SPACE

int rob(vector<int>& nums) {
	int prev1=0,prev2=0,temp;
	if(nums.size()==0) return 0;
	for(auto num:nums){
		temp=prev1;
		prev1=max(prev2+num,prev1);	//rob curr + rob n-2th or rob n-1th not curr one 
		prev2=temp;
	}
	return prev1;
}
