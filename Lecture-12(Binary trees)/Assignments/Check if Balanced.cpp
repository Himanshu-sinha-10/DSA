int find_height(BinaryTreeNode<int> *node)
{
    if(node==NULL)
        return 0;
    
    return max(find_height(node->left),find_height(node->right))+1;
}

bool isBalanced(BinaryTreeNode<int> *root) {
    // Write your code here
    if(root==NULL)
        return true;
    bool left_ans=isBalanced(root->left);
    bool right_ans=isBalanced(root->right);
    if(left_ans && right_ans)
    {
         int left_height=find_height(root->left);
         int right_height=find_height(root->right);
    
        if(abs(left_height-right_height)<=1)
        return true;
        else return false;
    }
    else return false;
   
    
    
    

}