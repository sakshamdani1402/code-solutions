// Given an array of N integers arr[] where each element represents the max number of steps that can be made forward from that element. 
// Find the minimum number of jumps to reach the end of the array (starting from the first element). 
// If an element is 0, then you cannot move through that element.

// Note: Return -1 if you can't reach the end of the array.

// Input:
// N = 11 
// arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9} 
// Output: 3 
// Explanation: 
// First jump from 1st element to 2nd 
// element with value 3. Now, from here 
// we jump to 5th element with value 9, 
// and from here we will jump to the last. 

int minJumps(int arr[], int n){
        if(n<=1) return 0;  //if arr has 1 or 0 elems
        if(arr[0]==0)   return -1;  //if we cant start
        
        int jumps=1, maxR=arr[0], steps=arr[0];
        
        for(int i=1;i<n;i++){
            if(i==n-1)  return jumps;   //we have reached the end
            maxR = max(maxR,i+arr[i]);  //update max reachable idx
            steps--;        //decrement steps
            if(steps==0){  //cant take steps any further
                jumps++;    //we have to take another jump
                if(maxR <= i)    return -1; //we have reached an idx greater than maxR
                steps=maxR-i;   //update steps
            }
        }
        return -1;
    }
