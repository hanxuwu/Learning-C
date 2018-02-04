/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
char* tree2str(struct TreeNode* t) {
    if(t==NULL) return "";
    char *tmp=NULL;
    if(t->left==NULL && t->right==NULL){
      tmp=calloc(10,sizeof(char));
      sprintf(tmp,"%d",t->val);
    }
    else if(t->left!=NULL && t->right==NULL){
        char *lefttmp=tree2str(t->left);
        tmp=calloc(strlen(lefttmp)+10,sizeof(char));
        sprintf(tmp,"%d(%s)",t->val,lefttmp);
    }
    else if(t->left==NULL && t->right!=NULL){
        char *righttmp=tree2str(t->right);
        tmp=calloc(strlen(righttmp)+10,sizeof(char));
        sprintf(tmp,"%d()(%s)",t->val,righttmp);
    }  
    else if(t->left!=NULL && t->right!=NULL){
        char *lefttmp=tree2str(t->left);
        char *righttmp=tree2str(t->right);
        tmp=calloc(strlen(lefttmp)+strlen(righttmp)+10,sizeof(char));
        sprintf(tmp,"%d(%s)(%s)",t->val,lefttmp,righttmp);
    }    
    return tmp;
}