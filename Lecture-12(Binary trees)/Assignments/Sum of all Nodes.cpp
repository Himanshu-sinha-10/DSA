int sumOfAllNodes(BinaryTreeNode<int>* root) {
    // Write your code here
    if(root==NULL)
        return 0;
    
    int left_sum=sumOfAllNodes(root->left);
    int right_sum=sumOfAllNodes(root->right);
    
    return root->data + left_sum + right_sum;

}