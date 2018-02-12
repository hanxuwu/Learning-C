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
    int *count=malloc(sizeof(int));
    *count=0;
    inOrder(root,array,count);
    for(int i=0;i<*count;i++){
        for(int j=i+1;j<*count;j++){
            if(array[j]<array[i]) return false;
        }
    }
    return true;
    
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