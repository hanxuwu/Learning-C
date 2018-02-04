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
#define MAX_LAYER 1000

void traverse(struct TreeNode*root,int i,double* temp,double*num,int *max){
    if (i>=(*max)) *max=i;
    if(root!=NULL){
        temp[i]+=root->val;
        num[i]+=1;
        traverse(root->left,i+1,temp,num,max);
        traverse(root->right,i+1,temp,num,max);
    }
}


double* averageOfLevels(struct TreeNode* root, int* returnSize) {
    double *temp = calloc(MAX_LAYER,sizeof(double));
    double *num = calloc(MAX_LAYER,sizeof(double));
    int max=0;
    traverse(root,0,temp,num,&max);
    *returnSize=max;
    for(int i=0;i<*returnSize;i++){
        if(num[i]!=0)
        temp[i]/=num[i];
    }
    return temp;
}


