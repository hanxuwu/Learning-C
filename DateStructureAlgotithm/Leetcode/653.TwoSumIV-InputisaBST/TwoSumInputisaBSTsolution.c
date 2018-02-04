/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int flag=0;

bool findTarget(struct TreeNode* root, int k) {
    struct TreeNode* start = root; // everytime the dfsearch should search from the start
    int final=dfs(root,k,start);
    if(flag==1) {flag=0;return true;}
    else return false;
    //return flag==1?true:false;

}

int dfs(struct TreeNode* root,int k,struct TreeNode* start){
    int result=0;
    if(root!=NULL){
        dfs(root->left,k,start); // use inorder traverse,the sequence is from the smallest to largest
        int current = root->val; 
        if(current!=k/2){ // ignore the current node
        result=dfsearch(start,k-current);} // looking for if exist another number add the current equal to the sum
        if (result==1) return 1;
        dfs(root->right,k,start);
            
    }
    return 0;
}

int dfsearch(struct TreeNode* root,int target){
    
    if(root!=NULL){
        dfsearch(root->left,target);
        if(root->val>target) return 0; // if the numebr larger than the target,no need to check it
        if(root->val==target) flag=1; // find the target
        dfsearch(root->right,target);
        
    }
    return 0;
}