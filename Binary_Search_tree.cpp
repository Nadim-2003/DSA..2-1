#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node
{
    int val;
    node *left;
    node *right;

    node(int value) : val(value), left(nullptr), right(nullptr) {}
};

node *insert(node *root, int n)
{
    if (!root)
        return new node(n);

    if (root->val > n)
    {
        root->left = insert(root->left, n);
    }
    else if (root->val < n)
    {
        root->right = insert(root->right, n);
    }
    return root;
}

bool search(node *root, int n)
{
    if (root == nullptr)
        return false;
    if (root->val == n)
        return true;
    if (root->val < n)
    {
        return  search(root->right, n);
    }
    else if (root->val > n)
    {
        return  search(root->left, n);
    }
}
node *findMax(node *root)
{
    while (root->right != nullptr)
    {
        root = root->right;
    }
    return root;
}
node *deletee(node *root, int n)
{
    if (root == nullptr)
        return root;

    if (root->val < n)
    {
        root->right = deletee(root->right, n);
    }
    else if (root->val > n)
    {
        root->left = deletee(root->left, n);
    }
    else
    {
        if (root->left == nullptr)
        {
            node *temp = root->right;
            delete root;
            return temp;
        }
        if (root->right == nullptr)
        {
            node *temp = root->left;
            delete root;
            return temp;
        }
        node *temp = findMax(root->left);
        root->val = temp->val;
        root->left = deletee(root->left, temp->val);
    }
    return root;
}
void inoder(node* root){
    if(!root) 
     return ;

     inoder(root->left);
     cout<<root->val<<" ";
     inoder(root->right);
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    node* root=nullptr;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        root = insert(root, arr[i]);
    }
    cout<<search(root,2)<<endl;
    root=deletee(root,2);
    inoder(root);
    return 0;
}