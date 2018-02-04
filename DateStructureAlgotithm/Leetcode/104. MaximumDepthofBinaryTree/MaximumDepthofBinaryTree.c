/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void traverse(struct TreeNode*root,int i,int * depth){
    if(i>=*depth) *depth=i;
    if(root!=NULL){
        traverse(root->left,i+1,depth);
        traverse(root->right,i+1,depth);
    }
}

int maxDepth(struct TreeNode* root) {
    int depth=0;
    traverse(root,0,&depth);
    return depth;
}