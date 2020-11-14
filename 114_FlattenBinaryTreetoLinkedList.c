void flatten(struct TreeNode* root){
    if (root == NULL) {
        return;
    }
    struct TreeNode* tmp = root->right;
    flatten(root->left);
    flatten(tmp);
    root->right = root->left;
    root->left = NULL;
    while (root->right != NULL) {
        root = root->right;
    }
    root->right = tmp;
    return 
}