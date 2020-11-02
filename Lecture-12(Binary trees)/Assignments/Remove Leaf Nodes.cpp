
BinaryTreeNode<int>* removeLeafNodes(BinaryTreeNode<int> *root) {
    // Write your code here
    if(root==NULL)
        return root;
    if(root->left==NULL && root->right==NULL)
        return NULL;
    root->left=removeLeafNodes(root->left);
    root->right=removeLeafNodes(root->right);
    return root;

}