/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    // divide and conquer
    
    int maxDepth(TreeNode *root) {
        int tempLeft,
            tempRight;
        if (root == NULL)
            return 0;
        else{
        	// 这里注意：
        	// 不能写成
        	// return maxDepth(root.left)>maxDepth(root.right) ?1+ maxDepth(root.left) :1+ maxDepth(root.right);
            // 这样的话就要执行两次 `maxDepth(root.left)`和`maxDepth(root.right)`
            // 性能下降一倍！！
            tempLeft = maxDepth(root -> left);
            tempRight = maxDepth(root -> right); 
            return tempLeft > tempRight ? tempLeft + 1 : tempRight + 1; 
        }        
    }
};