struct TreeNode* helper(int* preorder, int preorderStart, int preorderEnd, int* inorder, int* idx) {
    if (preorderStart > preorderEnd)
        return NULL;
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = preorder[(*idx)++];
    if (preorderStart == preorderEnd) {
        root->left = NULL;
        root->right = NULL;
        return root;
    }

    int inIndex = 0;
    for (int i = preorderStart; i <= preorderEnd; i++) {
        if (inorder[i] == root->val) {
            inIndex = i;
            break;
        }
    }
    root->left = helper(preorder, preorderStart, inIndex - 1, inorder, idx);
    root->right = helper(preorder, inIndex + 1, preorderEnd, inorder, idx);
    return root;
}


struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize){
    if (preorderSize == 0 || inorderSize == 0)
        return NULL;
    else if (preorderSize == 1) {
        struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        root->left = NULL;
        root->right = NULL;
        root->val = preorder[0];
        return root;
    }
    int idx = 0; 

    struct TreeNode* root = helper(preorder, 0, preorderSize - 1, inorder, &idx);
    return root;
}
