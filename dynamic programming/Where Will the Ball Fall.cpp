/* You have a 2-D grid of size m x n representing a box, and you have n balls. The box is open on the top and bottom sides.
Each cell in the box has a diagonal board spanning two corners of the cell that can redirect a ball to the right or to the left.
A board that redirects the ball to the right spans the top-left corner to the bottom-right corner and is represented in the grid as 1.
A board that redirects the ball to the left spans the top-right corner to the bottom-left corner and is represented in the grid as -1.
We drop one ball at the top of each column of the box. Each ball can get stuck in the box or fall out of the bottom. A ball gets stuck if it hits a "V" shaped pattern between two boards or if a board redirects the ball into either wall of the box.
Return an array answer of size n where answer[i] is the column that the ball falls out of at the bottom after dropping the ball from the ith column at the top, or -1 if the ball gets stuck in the box.

Input: grid = [[1,1,1,-1,-1],[1,1,1,-1,-1],[-1,-1,-1,1,1],[1,1,1,1,-1],[-1,-1,-1,-1,-1]]
Output: [1,-1,-1,-1,-1]
Explanation: This example is shown in the photo.
-- Ball b0 is dropped at column 0 and falls out of the box at column 1.
-- Ball b1 is dropped at column 1 and will get stuck in the box between column 2 and 3 and row 1.
-- Ball b2 is dropped at column 2 and will get stuck on the box between column 2 and 3 and row 0.
-- Ball b3 is dropped at column 3 and will get stuck on the box between column 2 and 3 and row 0.
-- Ball b4 is dropped at column 4 and will get stuck on the box between column 2 and 3 and row 1.

Input: grid = [[-1]]
Output: [-1]
Explanation: The ball gets stuck against the left wall.

Input: grid = [[1,1,1,1,1,1],[-1,-1,-1,-1,-1,-1],[1,1,1,1,1,1],[-1,-1,-1,-1,-1,-1]]
Output: [0,1,2,3,4,-1] */

int r,c;
bool valid(int i, int j){
    return i>=0 && j>=0 && j<c && i<r;
}
int solve(vector<vector<int>>& g, int i, int j){
    if(i==r) return j;  //if reached last row return col
    if(!valid(i,j)) return -1;  //if not valid
    /*now we check 2 things:
      -- if curr elem = 1 then adj elem should not be -1 and should be on a valid idx, else "V" will from or we wouldnt be on valid idx
      -- if curr elem = -1 then adj left elem should not be 1 ----------- "" ------------ */      
    if(g[i][j]==1 && valid(i,j+1) && g[i][j+1]!=-1) return solve(g, i+1, j+1);  
    else if(g[i][j]==-1 && valid(i,j-1) && g[i][j-1]!=1) return solve(g,i+1,j-1);

    return -1;  //return -1 if none of the abv holds true
}
vector<int> findBall(vector<vector<int>>& grid) {
    int m = grid.size(),  n = grid[0].size();
    r=m, c=n;
    vector<int> res(n);

    for(int i=0; i<n; i++){
        res[i] = solve(grid, 0, i);
    }

    return res;
}

//ITERATIVE APPROACH
vector<int> findBall(vector<vector<int>>& grid) {
  int m = grid.size(), n = grid[0].size();
  vector<int> res(n,0);

  for(int i=0; i<n; i++){
      int row=0, col=i;
      //while row is valid
      while(row < m){
          //do the same checks as in recursive soln
          if(grid[row][col]==1 && col+1<n && grid[row][col+1]!=-1)  
              row++, col++;
          else if(grid[row][col]==-1 && col-1>=0 && grid[row][col-1]!=1) 
              row++, col--;
          else break; //else we break 
      }
      //have we reached the last row ? return col else -1
      res[i] = row == m ? col : -1;
  }

  return res;
}
