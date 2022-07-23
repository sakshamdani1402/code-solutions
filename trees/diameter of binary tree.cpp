/* Given the root of a binary tree, return the length of the diameter of the tree.
The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.
The length of a path between two nodes is represented by the number of edges between them.

Input: root = [1,2,3,4,5]
Output: 3
Explanation: 3 is the length of the path [4,2,1,3] or [5,2,1,3].

Input: root = [1,2]
Output: 1 */
    
    
int  dia=0; //class var
int dfs(TreeNode* root){
    if(!root) return 0; 
    int left = dfs(root->left); //left height
    int right = dfs(root->right);   //right height
    dia = max(dia, left+right);     //calc dia for every node
    return 1 + max(left, right);    //return height 
}
int diameterOfBinaryTree(TreeNode* root) {
    dfs(root);  //just call we dont store anything, as dfs returns height and we need dia
    return dia; 
}
