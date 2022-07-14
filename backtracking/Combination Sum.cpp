// Given an array of integers and a sum B, find all unique combinations in the array where the sum is equal to B. 
// The same number may be chosen from the array any number of times to make B.
// Note:
//         1. All numbers will be positive integers.
//         2. Elements in a combination (a1, a2, …, ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
//         3. The combinations themselves must be sorted in ascending order.

// Input:
// N = 4
// arr[] = {7,2,6,5}
// B = 16
// Output:
// (2 2 2 2 2 2 2 2), (2 2 2 2 2 6), (2 2 2 5 5), (2 2 5 7), (2 2 6 6), (2 7 7), a(5 5 6)

// Input:
// N = 11
// arr[] = {6,5,7,1,8,2,9,9,7,7,9}
// B = 6
// Output:
// (1 1 1 1 1 1), (1 1 1 1 2), (1 1 2 2), (1 5), (2 2 2), (6)

vector<vector<int>> res;
vector<int> combi;
int n;
void backtrack(vector<int> &A, int target, int curr){
    //we subtracted too much
    if(target < 0)
        return;
    //we found our target sum
    if(target == 0){
        res.push_back(combi);
        return;
    }

    for(int i = curr; i<n ; i++){
        
        //we can use a no multiple time but there can be 
        //multiple instances of the same no in A
        //we remove duplicates here
        if(i == curr || A[i] != A[i-1]){
            combi.push_back(A[i]);
            
            //we can use a no multiple times so backtrack from the curr index
            backtrack(A, target-A[i], i);
            combi.pop_back();
        }
    }
}
vector<vector<int> > combinationSum(vector<int> &A, int B) {
    n = A.size();
    sort(A.begin(), A.end());
    backtrack(A,B,0);
    return res;
}
