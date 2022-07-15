// Given an integer array nums, find a contiguous non-empty subarray within the array that has the largest product, and return the product.
// The test cases are generated so that the answer will fit in a 32-bit integer.
// A subarray is a contiguous subsequence of the array.

// Input: nums = [2,3,-2,4]
// Output: 6
// Explanation: [2,3] has the largest product 6.

// Input: nums = [-2,0,-1]
// Output: 0
// Explanation: The result cannot be 2, because [-2,-1] is not a subarray.

// * if the arr contains only+ve ints we take product of all elems to get max product
// * but since here in this dp problem, we can have -ve as well as 0s
// * we maintain 2 vars max and min which store the current max and min products till now (leaving the elem at curr index aside)
// * if we encounter a -ve elem, we swap the vals of max and min, as max would become -ve and min would become +ve after multiplication with -ve no, so max becomes min and vice versa
// * now the max and min product can be the max or min * curr elem, or the curr elem itself 
// * take the eg : [-1,8], the curr max and min is -1, then max or min x 8 both will be -8 where as the subarr with max product should be 8, this also deals with 0 
// * at last we update the res with taking max of res and max

int maxProduct(vector<int>& nums) {
    int minp=1, maxp=1, res=INT_MIN;

    for(int &i: nums){
        if(i<0) swap(minp,maxp);

        minp = min(minp*i, i);
        maxp = max(maxp*i, i);

        res = max(res, maxp);
    }
    return res;
}
