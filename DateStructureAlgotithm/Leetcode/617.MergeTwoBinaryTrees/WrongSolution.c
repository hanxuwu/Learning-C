
//WRONG SOLUTION

/*
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* mergeTrees(struct TreeNode* t1, struct TreeNode* t2) {
    if(t1==NULL && t2==NULL) return NULL;
    else if(t1!=NULL && t2==NULL){
        t2=malloc(sizeof(struct TreeNode));
        t2->val=0;
        t2->val =t1->val;
        t2->left=NULL;
        t2->right=NULL;
        mergeTrees(t1->left,t2->left);
        mergeTrees(t1->right,t2->right);  
    }else if(t1==NULL && t2!=NULL){
        t1=malloc(sizeof(struct TreeNode));
        t1->val=0;
        //t1->val+=t2->val;
        t2->val +=t1->val;
        t1->left=NULL;
        t1->right=NULL;
        mergeTrees(t1->left,t2->left);
        mergeTrees(t1->right,t2->right);
    }else{
        //t1->val +=t2->val;
        t2->val +=t1->val;
        mergeTrees(t1->left,t2->left);
        mergeTrees(t1->right,t2->right);        
    }
    return t2;
    
}