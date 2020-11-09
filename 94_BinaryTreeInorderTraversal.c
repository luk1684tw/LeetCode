int* inorderTraversal(struct TreeNode* root, int* returnSize){
    *returnSize = 0;
    int* ans = (int*) malloc(sizeof(int) * 100);
    traverse(root, returnSize, &ans);
    return ans;
}

void traverse(struct TreeNode* root, int* returnSize, int** ans) {
    if (root == NULL) {
        return;
    } else {
        traverse(root->left, returnSize, ans);
        (*ans)[(*returnSize)++] = root->val;
        traverse(root->right, returnSize, ans);
    }
    return;
}