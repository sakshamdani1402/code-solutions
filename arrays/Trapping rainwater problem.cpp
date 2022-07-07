// Given an array arr[] of N non-negative integers representing the height of blocks. If width of each block is 1, compute how much water can be trapped between the blocks during the rainy season. 

// Input:
// N = 4
// arr[] = {7,4,0,9}
// Output:
// 10
// Explanation:
// Water trapped by above 
// block of height 4 is 3 units and above 
// block of height 0 is 7 units. So, the 
// total unit of water trapped is 10 units.

//at any idx the amount of water than can be stored is given my min(lmax,rmax)-arr[i]
//this means we do not care what is the highest tower on the left or right, we just need the smaller of the 2

long long trappingWater(int arr[], int n){
        long long rmax=0,lmax=0;
        long long left=0, right=n-1;
        long long res=0;
        while(left<=right){
					// We need check for minimum of left 
      		// and right max for each element
            if(lmax<rmax){
                lmax = max(lmax,arr[left]);	//update lmax
                res+=lmax-arr[left++];			//amnt of water stored is left bounday - curr height, if curr elem is the tallest 0 would be added as there is no taller 																							elem to the left
            }
            else{
                rmax = max(rmax,arr[right]);
                res+=rmax-arr[right--];
            }
        }
        
        return res;
    }
