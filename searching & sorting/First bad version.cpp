// You are a product manager and currently leading a team to develop a new product. Unfortunately, the latest version of your product fails the quality check. 
// Since each version is developed based on the previous version, all the versions after a bad version are also bad.
// Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, which causes all the following ones to be bad.
// You are given an API bool isBadVersion(version) which returns whether version is bad. Implement a function to find the first bad version. 
// You should minimize the number of calls to the API.

// Input: n = 5, bad = 4
// Output: 4
// Explanation:
// call isBadVersion(3) -> false
// call isBadVersion(5) -> true
// call isBadVersion(4) -> true
// Then 4 is the first bad version.

//you can use linear search but it will call API at every step
//we can reduce calls by using binary search

int firstBadVersion(int n) {
    int lo=1,hi=n; 

    while(lo<hi){ //if we do lo<=high, it will keep looping for lo=high, because when lo=hi we have reached our ans
       int mid= lo+(hi-lo)/2;
       if(!isBadVersion(mid)) lo=mid+1; //if this is not badversion, then  bad version lies to the RHS
       else hi=mid; //else this is a badversion, this may be the 1st or there may be prev badversion on LHS, so hi=mid
   } 
    return lo;  //return either lo or high as both will converge at 1 elem
}
