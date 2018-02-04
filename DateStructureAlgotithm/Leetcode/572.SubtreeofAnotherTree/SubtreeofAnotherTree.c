/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isEqual(struct TreeNode* s,struct TreeNode* t){
    if(s==NULL||t==NULL) // when there is one tree is NULL
        return s==t;   // if both tree is NULL, return true
    if(s->val==t->val) return isEqual(s->left,t->left) && isEqual(s->right,t->right); // check all the root
    return false;
}

bool isSubtree(struct TreeNode* s, struct TreeNode* t) {
    if(s==NULL) return false; // after checking all the tree if not find ,return false
    if(isEqual(s,t)==false) return(isSubtree(s->left,t)||isSubtree(s->right,t)); // check all the tree
    return true; // if equal return true
}
