#include<bits/stdc++.h>

void printLevelATNewLine(BinaryTreeNode<int> *root) {
    // Write your code here
    if(root==NULL)
        return;
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
        BinaryTreeNode<int> * front=q.front();
        q.pop();
        if(front==NULL)
        {
            if(q.empty())
                break;
            else
            {
            cout<<endl;
            q.push(NULL);
            }
        }
        else
        {
        cout<<front->data<<" ";

        if(front->left)
            q.push(front->left);
        if(front->right)
            q.push(front->right);
        }
    }

}
