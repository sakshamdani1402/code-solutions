// Given an array arr[] of distinct integers of size N and a value sum, the task is to find the count of triplets (i, j, k), 
// having (i<j<k) with the sum of (arr[i] + arr[j] + arr[k]) smaller than the given value sum.

// Input: N = 4, sum = 2
// arr[] = {-2, 0, 1, 3}
// Output:  2
// Explanation: Below are triplets with 
// sum less than 2 (-2, 0, 1) and (-2, 0, 3). 

long long countTriplets(long long arr[], int n, long long sum){   
  sort(arr,arr+n);    //sort + meet in middle concept
  long long ans=0;
  // Your code goes here
  for(int i=0;i<n-2;i++){ //cuz i<j<k, we leave 2 elem for j & k
      //set 2 corner pts to meet in middle
      int j=i+1,k=n-1;    
      while(j<k){
          if(arr[i] + arr[j] + arr[k] >=sum)
              k--;    //we need a smaller value so that 
                      //sum becomes smaller so decrease k
          else{
              ans+= (k-j);    //since sum is smaller than target
                              //all the values between j,k will
                              //have sum smaller that target
                              //therefore we will jave k-j
                              //triplets
              // now we move j to find next bigger sum 
              //if there is any
              j++;
          }
      }
  }
  return ans;
}
