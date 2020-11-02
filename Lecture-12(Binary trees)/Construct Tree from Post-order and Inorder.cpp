BinaryTreeNode<int>* buildhelper(int* postorder,int poststart,int postend,int* inorder,int instart,int inend)
{
    if(instart>inend)
        return NULL;
    int rootdata=postorder[postend];

    int rootIndex;
    for(int i=instart;i<=inend;i++)
    {
        if(inorder[i]==rootdata)
        {
            rootIndex=i;
            break;
        }
    }
    int lins=instart;
    int line=rootIndex-1;
    int lps=poststart;
    int lpe=line-lins+lps;
    int rins=rootIndex+1;
    int rine=inend;
    int rps=lpe+1;
    int rpe=postend-1;
    
    
    BinaryTreeNode<int>* root=new BinaryTreeNode<int>(rootdata);
    root->left=buildhelper(postorder,lps,lpe,inorder,lins,line);
    root->right=buildhelper(postorder,rps,rpe,inorder,rins,rine);
    
    return root;

    
        
}

BinaryTreeNode<int>* getTreeFromPostorderAndInorder(int *postorder, int postLength, int *inorder, int inLength) {
    // Write your code here
    return buildhelper(postorder,0,postLength-1,inorder,0,inLength-1);

}