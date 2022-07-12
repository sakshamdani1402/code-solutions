// You are given an integer array nums. You want to maximize the number of points you get by performing the following operation any number of times:
// Pick any nums[i] and delete it to earn nums[i] points. Afterwards, you must delete every element equal to nums[i] - 1 and every element equal to nums[i] + 1.
// Return the maximum number of points you can earn by applying the above operation some number of times.

// Input: nums = [2,2,3,3,3,4]
// Output: 9
// Explanation: You can perform the following operations:
// - Delete a 3 to earn 3 points. All 2's and 4's are also deleted. nums = [3,3].
// - Delete a 3 again to earn 3 points. nums = [3].
// - Delete a 3 once more to earn 3 points. nums = [].
// You earn a total of 9 points.

//METHOD 1 - DP + MEMO
unordered_map<int,int> hash,dp;
int solve(int num){
    if(num==0) return 0;  //if num zero sum would be zero
    if(num==1) return hash[num] ? hash[num] : 0;  //if we have 1 in hashmap then return the sum else return 0 (if we dont return for 1, num-2 and num-1 would give err)
    if(dp.find(num)!=dp.end()) return dp[num];  //if memoized

    return dp[num] = max(solve(num-1), hash[num]+ solve(num-2));   //dont take curr, take n-1th or take curr and n-2th
}
int deleteAndEarn(vector<int>& nums) {
    int maxnum=0; 
    //for every num, update sum and find max num from the i/p
    for(int &i:nums){
        hash[i]+=i;
        if(i>maxnum) maxnum=i;
    } 
    return solve(maxnum);
}

//iterative house robber technique
  int deleteAndEarn(vector<int>& nums) {
    //return for  base cases
    if(nums.size()==0) return 0;
    if(nums.size()==1) return nums[0];

    unordered_map<int,int> hash;
    int maxnum=0;
    //update sum of elems and find max number in i/p
    for(int &i: nums){
        hash[i]+=i;
        maxnum = max(maxnum,i);
    }
    int res, prev2=0, prev1=hash[1]; //prev1 = sum of all 1s
   
    for(int i=2; i<=maxnum; i++){
        res = max(prev2 + hash[i], prev1);  //res = curr num + sum of num-2 or not take curr num take sum od n-1th num
        prev2 = prev1;  //update prev1 and prev2
        prev1 = res;
    }

    return res;
}
