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
#define MAX(X,Y) (((X)>(Y))?(X):(Y))

/*

just consider the depthest left and depthest right

*/
int getHeight(struct TreeNode* root){
    if (root==NULL)
        return 0;
    else
        return 1 + MAX(getHeight(root->left), getHeight(root->right));
}

int addHeight(struct TreeNode* root,int i){
    if(root!=NULL){
        addHeight(root->left,i+1);
        root->val += i;
        addHeight(root->right,i+1);
    }
    return 0;
}

int main(void){
    Tree root = newNode(5);
    //TreeInsert(root,5);
    TreeInsert(root,3);
    TreeInsert(root,6);
    TreeInsert(root,2);
    TreeInsert(root,4);
    TreeInsert(root,7);
    TreeInsert(root,8);
    showTree(root);
    printf("height:%d\n\n", getHeight(root));

    addHeight(root,0);
    showTree(root);

}