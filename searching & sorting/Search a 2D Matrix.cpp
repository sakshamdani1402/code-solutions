/* Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:
Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.

Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true

Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
Output: false */
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int low =0, r = matrix.size(), c=matrix[0].size(), high = r*c-1;
    //since there are row*col elems
    //array index would be r*c-1;
    while(low <= high){
        int mid = low + (high-low)/2;
        if(matrix[mid/c][mid%c] == target) return true;
        else if(matrix[mid/c][mid%c] > target)  high = mid-1;
        else low = mid+1;
    }
    return false;
}
