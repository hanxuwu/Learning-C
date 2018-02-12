/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#include <stdio.h>
#include "BSTree.h"
#include <stdlib.h>

#define MAX 1000

/*

just consider the depthest left and depthest right

*/
int diameterOfBinaryTree(struct TreeNode* root) {
    if (root==NULL) return 0;
    int maxL=0;
    int maxR=0;
    int max=0;
    maxL=getHeight(root->left,0,&max);
    max=0;
    maxR=getHeight(root->right,0,&max);
    return maxL+maxR+1;
}

int getHeight(struct TreeNode* root,int height,int *max){
    if((*max)<height) *max=height;
    if(root!=NULL){
        getHeight(root->left,height+1,max);
        getHeight(root->right,height+1,max);
    }
    return *max;
}


int main(void){
    Tree root = newNode(5);
    //TreeInsert(root,5);
    TreeInsert(root,3);
    TreeInsert(root,6);
    TreeInsert(root,2);
    TreeInsert(root,4);
    TreeInsert(root,7);
    showTree(root);
    isValidBST(root);

}