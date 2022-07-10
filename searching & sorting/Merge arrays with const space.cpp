// Given two sorted arrays arr1[] and arr2[] of sizes n and m in non-decreasing order. 
// Merge them in sorted order without using any extra space. Modify arr1 so that it contains the first N elements and modify arr2 so that it contains the last M elements.

// Input: 
// n = 4, arr1[] = [1 3 5 7] 
// m = 5, arr2[] = [0 2 6 8 9]
// Output: 
// arr1[] = [0 1 2 3]
// arr2[] = [5 6 7 8 9]
// Explanation:
// After merging the two 
// non-decreasing arrays, we get, 
// 0 1 2 3 5 6 7 8 9.

//method-1 using insertion sort
//TC - (worst case) O(n*m)
//  Iterate through every element of ar2[] starting from last 
//  element. Do following for every element ar2[i]
//     a) Store last element of ar1[i]: last = ar1[i]
//     b) Loop from last element of ar1[] while element ar1[j] is 
//        greater than ar2[i].
//           ar1[j+1] = ar1[j] // Move element one position ahead
//           j--
//     c) If any element of ar1[] was moved or (j != m-1)
//           ar1[j+1] = ar2[i] 
//           ar2[i] = last
void merge(long long arr1[], long long arr2[], int n, int m){ 
    for(int i=m-1;i>=0;i--){
        int last=arr1[n-1];
        int j=n-2;
      /* Find the smallest element greater than ar2[i].
        Move all elements one position ahead till the
        smallest greater element is not found */
        while(j>=0 and arr1[j]>arr2[i]){
            arr1[j+1]=arr1[j];
            j--;
        }
        // If there was a greater element
        if(j!=n-2 || last>arr2[i]){
            arr1[j+1]=arr2[i];
            arr2[i]=last;
        }
    }
} 

//method 2 using swapping and ordering
//TC - O((n+m) log(n+m))
void merge(long long arr1[], long long arr2[], int n, int m){ 
    int i=0,j=0,k=n-1;
    while(i<=k and j<m){
        if(arr1[i]<arr2[j]) i++;          //elems are in order
        else swap(arr1[k--],arr2[j++]);   //put kth elem of arr1 in jth position in arr2, this way smaller elems are in arr1 and greater elems are arranged in arr2
    }
    //now all elems in arr1 are smaller than all elems in arr2
    //so sort them to merge them
    sort(arr1,arr1+n);  
    sort(arr2,arr2+m);
} 
