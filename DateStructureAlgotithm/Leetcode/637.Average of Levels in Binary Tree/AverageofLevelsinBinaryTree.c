/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
double* averageOfLevels(struct TreeNode* root, int* returnSize) {
    
    
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

void traverseR(struct TreeNode*root,int * returnSize,double* temp){
    if(root!=NULL){
        *returnSize+=1;
        //traverse(root->left,returnSize);
        temp[*returnSize]+=root->val;
        temp[*returnSize]+=root->val;
        traverseR(root->right,returnSize,temp);
    }
}

void traverseL(struct TreeNode*root,int * returnSize,double* temp){
    if(root!=NULL){
        //*returnSize+=1;
        temp[*returnSize]+=root->val;
        traverseL(root->left,returnSize,temp);
        traverseL(root->right,returnSize,temp);
    }
}

void traverse(struct TreeNode*root,int i,double* temp,double*num){
    if(root!=NULL){
        temp[i]+=root->val;
        num[i]+=1;
        traverse(root->left,i+1,temp,num);
        traverse(root->right,i+1,temp,num);
    }
}


double* averageOfLevels(struct TreeNode* root, int* returnSize) {
    double * new;
    *returnSize=0;
    double *temp = calloc(100,sizeof(double));
    double *num = calloc(100,sizeof(double));
    traverse(root,0,temp,num);
   
    //traverseL(root,returnSize,temp);
    //*returnSize=0;
    //traverseR(root,returnSize,temp);
    //new = malloc((*returnSize) *sizeof(double));
    
    //new[0]=*returnSize;
    *returnSize=10;
    return num;
}


