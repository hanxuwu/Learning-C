/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#define MAX 10000

void inOrder(struct TreeNode* root,int * array,int *count){
    if(root!=NULL){
        inOrder(root->left,array,count);
        *(array+*count)=root->val;
        (*count)++;
        inOrder(root->right,array,count);   
    }
}

bool isValidBST(struct TreeNode* root) {
    int *array=malloc(MAX*sizeof(int));
    int count=0;
    inOrder(root,array,&count);
    for(int i=0;i<count;i++){
        for(int j=i+1;j<count;j++){
            if(array[j]<=array[i]) return false;
        }
    }
    return true;
    
}