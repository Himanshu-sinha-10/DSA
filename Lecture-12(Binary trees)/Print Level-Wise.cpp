
void printLevelWise(BinaryTreeNode<int> *root) {
	// Write your code here
    queue<BinaryTreeNode<int>* > q;
    q.push(root);
    while(!q.empty())
    {
        BinaryTreeNode<int>* curr=q.front();
        q.pop();
        cout<<curr->data<<":";
        if(curr->left)
        {
            q.push(curr->left);
            cout<<"L:"<<curr->left->data<<",";
        }
        else 
        {
            cout<<"L:-1,";
        }
        if(curr->right)
        {
            q.push(curr->right);
            cout<<"R:"<<curr->right->data<<endl;
        }
        else
        {
            cout<<"R:-1"<<endl;
        }
    }
}