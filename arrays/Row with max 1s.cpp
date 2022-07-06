// Given a binary 2D array of n x m dimensions where each row is sorted. 
// Find the 0-based index of the first row that has the maximum number of 1's.

// Input: 
// N = 4 , M = 4
// Arr[][] = {{0, 1, 1, 1},
//            {0, 0, 1, 1},
//            {1, 1, 1, 1},
//            {0, 0, 0, 0}}
// Output: 2
// Explanation: Row 2 contains 4 1's (0-based
// indexing).

//0(n^2) solution is trivial, other efficient methods include - 
// 1- Since each row is sorted, we can use Binary Search to count of 1s in each row. We find the index of first instance of 1 in each row. 
//    The count of 1s will be equal to total number of columns minus the index of first 1.
// 2-  Instead of doing binary search in every row, we first check whether the row has more 1s than max so far. If the row has more 1s, 
//      then only count 1s in the row. Also, to count 1s in a row, we don’t do binary search in complete row, we do search in before the index of last max. 
// 3 - we use the best method o(n+m) time

int j = m-1, res=0; //init j to the last col
for(int i=0;i<n;i++){

  bool isRowWithMax1s=false; //init a flag

  while(j>=0 and arr[i][j]==1){ //if j is inbounds and curr elem is one then decrease j till we find 1s
      j--;
      isRowWithMax1s=true;  //this will only stay true for the row with max zeros, cuz j would be set to a col where the current max no. of 1s are
      //if in the new row and the same col doesnt have a one then the while loop will not run as this row has less 1s than the curr max row
  }

  if(isRowWithMax1s) res = i; //set this row as the row with max 1s
}
if(res==0 and arr[0][m-1]==0) return -1;  //if in the 1st row the last elem was zero and res is also zero then there wont be any row with 1 so return -1
return res;
