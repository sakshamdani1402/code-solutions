// Given an array of integers. Find the Inversion Count in the array. 
// Inversion Count: For an array, inversion count indicates how far (or close) the array is from being sorted.
// If array is already sorted then the inversion count is 0. If an array is sorted in the reverse order then the inversion count is the maximum. 
// Formally, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.

// Input: N = 5, arr[] = {2, 4, 1, 3, 5}
// Output: 3
// Explanation: The sequence 2, 4, 1, 3, 5 
// has three inversions (2, 1), (4, 1), (4, 3).

//inversions at curr idx = num of elems on RHS smaller than the curr elem. we need O(N^2) by simple method, we use merge sort so here
//inversion = num of elems between curr elem and mid(start pt of 2nd half of arr in merge sort)
long long int inversions=0;
vector<long long> temp; //temp arr for merge sort

void merge(long long arr[], int low,int mid, int high){
    int i=low,j=mid,k=low;
    //1st half = [low,mid-1]
    //2nd half = [mid,high]
    while(i<mid && j<=high){
        if(arr[i]<=arr[j]) temp[k++] = arr[i++];  //arr[i]<=arr[j], means elems are in order so there isnt any inversion here
        else temp[k++]=arr[j++], inversions+=(mid-i);   //arr[i]>arr[j], means elems are out of order, and the num of elems that are out of order are "mid-i"
    }
    //place all remaining elements (if left)
    while(i<mid) temp[k++]=arr[i++];  
    while(j<=high) temp[k++]=arr[j++];
    //place elems in original array
    for(int x=low;x<=high;x++) arr[x]=temp[x];
}

void mergesort(long long arr[], int low, int high){
    //normal merge sort
    //1st half = [low,mid-1]
    //2nd half = [mid,high
    if(low<high){
        int mid = low + (high-low)/2;
        mergesort(arr,low,mid);
        mergesort(arr,mid+1,high);
        merge(arr,low,mid+1,high);
    }
}

long long int inversionCount(long long arr[], long long N){
    temp.resize(N);
    mergesort(arr,0,N-1);
    return inversions;
}
