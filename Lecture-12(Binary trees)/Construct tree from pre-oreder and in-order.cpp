BinaryTreeNode<int>* buildHelper(int* preorder,int prestart,int preend,int* inorder,int instart,int inend)
{
    if(instart>inend)
        return NULL;
    int rootData=preorder[prestart];
    int rootindex;
    for(int i=instart;i<=inend;i++)
    {
        if(inorder[i]==rootData)
        {    rootindex=i;
             break; 
        }
    }
    int lps=prestart+1;
    int lis=instart;
    int lie=rootindex-1;
    int lpe=lie-lis+lps;
    int rps=lpe+1;
    int rpe=preend;
    int ris=rootindex+1;
    int rie=inend;
    
    BinaryTreeNode<int>* root=new BinaryTreeNode<int>(rootData);
    root->left=buildHelper(preorder,lps,lpe,inorder,lis,lie);
    root->right=buildHelper(preorder,rps,rpe,inorder,ris,rie);
    return root;
    
}


BinaryTreeNode<int>* buildTree(int *preorder, int preLength, int *inorder, int inLength) {
    // Write your code here
    return buildHelper(preorder,0,preLength-1,inorder,0,inLength-1);

}
