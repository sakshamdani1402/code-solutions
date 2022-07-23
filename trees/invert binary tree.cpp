/* Given the root of a binary tree, invert the tree, and return its root.

Input: root = [4,2,7,1,3,6,9]
Output: [4,7,2,9,6,3,1]

Input: root = [2,1,3]
Output: [2,3,1]

Input: root = []
Output: [] */

TreeNode* invertTree(TreeNode* root) {
    if(!root) return root;
    auto node = root->left;
    root->left = invertTree(root->right);   //set left substree to right
    root->right = invertTree(node);         //set right to left
    return root;
}
