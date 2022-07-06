//You are given an array arr[] of N integers including 0. The task is to find the smallest positive number missing from the array.
// Input:
// N = 5
// arr[] = {0,-10,1,3,-20}
// Output: 2
// Explanation: Smallest positive missing 
// number is 2.

int find(int arr[], int n){
        for(int i=0;i<n;i++){
            if(abs(arr[i])-1<n && arr[abs(arr[i])-1] >0)  //if elem at curr idx<n and arr[curr elem -1] is +ve
            arr[abs(arr[i])-1]= -arr[abs(arr[i])-1];      //mark elem at this idx as -ve
        }
        
        for(int i=0;i<n;i++) if(arr[i]>0) return i+1;     //since arr are 0 indexed return i+1th position
        
        return n+1; //coming here means no number was missing so we return n+1th number
    }
    int missingNumber(int arr[], int n){
        int idx=0;
        for(int i=0;i<n;i++){
            if(arr[i]<=0) swap(arr[i],arr[idx++]);  //put all -ve nums to the left
        }
        //n-idx is the size of the remaing arr
        return find(arr+idx,n-idx); //arr+idx (array in c++ work on pointers, doing this we only send the arr from jth idx)
    } 

// Following is the two step algorithm. 
// 1) Segregate positive numbers from others i.e., move all non-positive numbers to left side. In the following code, segregate() function does this part. 
// 2) Now we can ignore non-positive elements and consider only the part of array which contains all positive elements. 
//   We traverse the array containing all positive numbers and to mark presence of an element x, we change the sign of value at index x to negative. 
//   We traverse the array again and print the first index which has positive value
