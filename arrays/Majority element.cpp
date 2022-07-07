// Given an array A of N elements. Find the majority element in the array. 
// A majority element in an array A of size N is an element that appears more than N/2 times in the array.

// Input:
// N = 5 
// A[] = {3,1,3,3,2} 
// Output:
// 3
// Explanation:
// Since, 3 is present more
// than N/2 times, so it is 
// the majority element.
//-----------------------------------------------------------------
// N = 3 
// A[] = {1,2,3} 
// Output:
// -1
// Explanation:
// Since, each element in 
// {1,2,3} appears only once so there 
// is no majority element.
//-----------------------------------------------------------------

    int majorityElement(int a[], int size){   
        // solved my moores voting algo
        int count = 0;
        int element = 0;
        
        //loop to find majority candidate element
        for(int i=0;i<size;i++){
            
            //if count becomes 0 we re-initialize element and
            //count with current element and 1 respectively
            //count becoming zero suggests the count ofmajority element 
            //was cancelled by the count of all minority elements so far
            if(count == 0){
                element = a[i]; 
                count =1;
            }
            // we decrease the count of the majoriy element so far if
            // we encounter a different element
            else if(element !=a[i])
                count--;
            // else we increase it
            else count++;
        }
        // here we have found the majority elem now we find the count of it
        // so we re-init count to 0 
        count=0;
        for(int i=0;i<size;i++)
            if(a[i]==element) count++;
        //finally if the count is > size/2 we return the element
        // else there was no majority elem in the array so return -1
        return count > size/2 ? element : -1;
    }
