#include<climits>
pair<int, int> getMinAndMax(BinaryTreeNode<int> *root) {
	// Write your code here
    if(root==NULL)
    {
        pair<int,int> p;
        p.first=INT_MAX;
        p.second=INT_MIN;
        return p;
    }
    
    
    pair<int,int> left_ans=getMinAndMax(root->left);
    pair<int,int> right_ans=getMinAndMax(root->right);
    
    int final_min=min(root->data,min(left_ans.first,right_ans.first));
    int final_max=max(root->data,max(left_ans.second,right_ans.second));
    
    pair<int,int> p;
    p.first=final_min;
    p.second=final_max;
    
    return p;
    
}