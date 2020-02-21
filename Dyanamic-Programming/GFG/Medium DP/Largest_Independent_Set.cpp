//https://practice.geeksforgeeks.org/problems/largest-independent-set-problem/1
int LISS(struct Node *root)
{
    //Code here
    if(root==NULL)
    {
        return 0;
    }
    int v1=LISS(root->left)+LISS(root->right);
    int v2=1;
    if(root->left)
    {
        v2+=LISS(root->left->left)+LISS(root->left->right);
    }
    if(root->right)
    {
        v2+=LISS(root->right->left)+LISS(root->right->right);
    }
    return max(v1,v2);
}
