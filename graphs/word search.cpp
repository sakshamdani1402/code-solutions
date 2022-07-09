// Given an m x n grid of characters board and a string word, return true if word exists in the grid.
// The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. 
// The same letter cell may not be used more than once.    

//Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], 
//word = "ABCCED"
//Output: true


// iterate over the 2d matrix and run dfs on every char
// if the char is present in the word continue further
// if the word is found return true else return false and continue 
// iterating over the matrix

bool exist(vector<vector<char>>& board, string word) {
    if(word=="") return false;

    for(int i=0; i<board.size(); i++){
        for(int j=0; j<board[0].size(); j++){
            if(board[i][j]==word[0] && search(board,i,j,word,0))
                return true;
        }
    }
    // we couldnt return true after iterating over the whole matrix
    // so the word isnt present, hence return false
    return false;
}
    
    
bool search(vector<vector<char>>& board, int i, int j,string word,int idx){
    if(idx==word.size()) //this means we have checked all the words
        return true;

    // check for out of bounds or char mismatch
    if(i<0 or j<0 or i>=board.size() or j>=board[0].size() or
      board[i][j] != word[idx]) return false; 

    // being here means char is matched so mark it visited and continue search
    board[i][j]='#';

    // check for the next char in all four directions and store the res
    bool res = search(board,i-1,j,word,idx+1) or search(board,i+1,j,word,idx+1)
        or search(board,i,j+1,word,idx+1) or search(board,i,j-1,word,idx+1);

    // mark unvisited for other searches
    board[i][j] = word[idx];

    //if the char was found even in 1 of the four directions then res would be             true else it would be false
    return res;
}
