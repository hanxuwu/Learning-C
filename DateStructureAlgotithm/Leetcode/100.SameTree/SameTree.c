/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    if(p==NULL||q==NULL) return p==q;
    if(p->val==q->val) return isSameTree(p->left,q->left)&&isSameTree(p->right,q->right);
    return false;
        
}