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

int dfs(Tree root,int k,Tree start);
int dfsearch(Tree root,int target);
bool findTarget(Tree root, int k);

int flag=0;

int dfs(Tree root,int k,Tree start){
    if(root!=NULL){
        printf("%d\n",root->data);
        int current = root->data;
        int result=dfsearch(start,k-current);
        if (result==1) return 1;
        dfs(root->right,k,start);
        dfs(root->left,k,start);    
    }
    return 0;
}

int dfsearch(Tree root,int target){
    if(root!=NULL){
        printf("#%d\n",root->data);
        if(root->data==target) flag=1;
        dfsearch(root->right,target);
        dfsearch(root->left,target);
    }
    return 0;
}

bool findTarget(Tree root, int k) {
    Tree start = root;
    int final=dfs(root,k,start);
    return final==1?true:false;

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
    printf("%d",findTarget(root,9));

}