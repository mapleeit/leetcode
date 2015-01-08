/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


// version 1; Accepted
// 这个方案要重复遍历，由于无法在第一次遍历的时候在每个结点处写入其到底部的高度，因此效率很低
class Solution {
public:
    bool isBalanced(TreeNode *root) {
    	if (root == NULL)
    	{
    	    return true;
    	}    
    	int l = getHeight(root->left),
    		r = getHeight(root->right);
    	if (abs(r - l) > 1)
    	{
    		return false;
    	}else{
    		return isBalanced(root->left) && isBalanced(root->right);
    	}

    }
    int getHeight(TreeNode *root){
    	if (root == NULL)
    	{
    		return 0;
    	}
    	int tempLeft = getHeight(root->left);
    	int tempRight = getHeight(root->right);
    	return tempLeft > tempRight ? tempLeft + 1 : tempRight + 1;
    }
};

// version 2 : Accepted
// more efficient

class Solution {
public:

    bool isBalanced(TreeNode *root) {
    	if (root == NULL)
    	{
    	    return true;
    	}    
    	return isBalancedAux(root) == UNBALANCED ? false : true;
    }

    static const int UNBALANCED = -1;

    int isBalancedAux(TreeNode *root){
    	if (root == NULL)
    	{
    		return 0;
    	}
    	int tempLeft = isBalancedAux(root->left),
    		tempRight = isBalancedAux(root->right);
    	if (tempLeft == UNBALANCED || tempRight == UNBALANCED){
    	    return UNBALANCED;
    	}
    	if (abs(tempLeft - tempRight) > 1)
    	{
    		return UNBALANCED;
    	}else{
    		return tempLeft > tempRight ? tempLeft + 1 : tempRight + 1;
    	}

    }
};