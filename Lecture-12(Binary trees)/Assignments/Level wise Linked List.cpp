vector<Node<int>*> constructLinkedListForEachLevel(BinaryTreeNode<int> *root) {
    // Write your code here
    if(root==NULL)
    {
    vector<Node<int>*> v;
        v.push_back(NULL);
        return v;
        
    }
    Node<int>* head=NULL;
    Node<int>* tail =NULL;
    vector<Node<int>*> v;
    
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
        BinaryTreeNode<int>* front=q.front();
        q.pop();
        if(front==NULL)
        {
            v.push_back(head);
            head=NULL;
            tail=NULL;
            if(!q.empty())
                q.push(NULL);
        }
        else
        {
             if(head==NULL)
        {
            head=new Node<int>(front->data);
            tail=head;
        }
        else
        {
            tail->next=new Node<int>(front->data);
            tail=tail->next;
        }
        
        if(front->left)
            q.push(front->left);
        
        if(front->right)
            q.push(front->right);
        
        }
       
    }
    return v;
    

}