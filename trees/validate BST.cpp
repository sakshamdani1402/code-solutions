// Given the root of a binary tree, determine if it is a valid binary search tree (BST).
// A valid BST is defined as follows:
// 	The left subtree of a node contains only nodes with keys less than the node's key.
// 	The right subtree of a node contains only nodes with keys greater than the node's key.
// 	Both the left and right subtrees must also be binary

// Input: root = [5,1,4,null,null,3,6]
// Output: false
// Explanation: The root node's value is 5 but its right child's value is 4.

bool check(TreeNode* root, TreeNode* min, TreeNode* max){
	if(!root) return true;	
	if((min && root->val <= min->val) || (max && root->val >= max->val)) return false; // min->val < root->val < max->val
	//check for left and right subtrees
	//for left subtree, min->val < root->left->val < root->val
	//for right subtree, root->val < root->right->val < max->val
	return check(root->left, min, root) && check(root->right, root, max);	
}
bool isValidBST(TreeNode* root) {
	 return check(root,NULL,NULL);	//root is 1st node, there is no prev min or max
}
