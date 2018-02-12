/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int MAX(int a, int b) //return the highest value of two int, usefull to compute the hight
 {
     return a > b? a :b;
 }

int height(struct TreeNode* root){
    if(root==NULL) return 0;
    return MAX(height(root->left),height(root->right))+1;
}

void dfs(struct TreeNode*root,int*maxi){
    if(root)
    {
        if(root->left&&!root->right)
            dfs(root->left,maxi);
        else if(root->right&&!root->left)
            dfs(root->right,maxi);
        else{
            int hei = height(root->left)+height(root->right);
            if(hei>*maxi) *maxi=hei;

            dfs(root->left,maxi);
            dfs(root->right,maxi);
        }
    }
}



int diameterOfBinaryTree(struct TreeNode* root) {
    if(root==NULL) return 0;
    int max;
    max=height(root->left)+height(root->right);
    dfs(root->left,&max);
    dfs(root->right,&max);
    return max;


}