// Given three arrays sorted in increasing order. Find the elements that are common in all three arrays.
// Note: can you take care of the duplicates without using any additional Data Structure?

// Input:
// n1 = 6; A = {1, 5, 10, 20, 40, 80}
// n2 = 5; B = {6, 7, 20, 80, 100}
// n3 = 8; C = {3, 4, 15, 20, 30, 70, 80, 120}
// Output: 20 80
// Explanation: 20 and 80 are the only
// common elements in A, B and C.

vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3){
    vector<int> res;
    int i=0,j=0,k=0;    
    int p1,p2,p3; 
    p1=p2=p3=INT_MIN;   //to store prev elems to handle duplicates

    while(i<n1 && j<n2 && k<n3){    //while any 1 list doesnt end
    while(A[i]==p1 && i<n1) i++;    //move ahead while there are
    while(B[j]==p2 && j<n2) j++;    //duplicates
    while(C[k]==p3 && k<n3) k++;

        if(A[i] == B[j] && B[j]==C[k]){ //if all elems are same
            res.push_back(A[i]);    //add to res
            p1=p2=p3=A[i];   //update prev elems
            i++; j++; k++;  //increment cursors
        }
        else if(A[i] < B[j]){   //ith and jth elems are not same
            p1=A[i];    //prev elem
            i++;        //move i
        }      
        else if(B[j] < C[k]){   //jth and kth elem are not same
            p2=B[j];    //set prev
            j++;        //move j
        }    
        else{
            p3=C[k];    //else kth elem is not same so set prev
            k++;        //move k
        }    
    }
    return res;
}
