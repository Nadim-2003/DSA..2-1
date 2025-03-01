//44
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node
{
  int val;
  node *left;
  node *mid;
  node *right;
  node(int n)
  {
    val = n;
    left = nullptr;
    mid = nullptr;
    right = nullptr;
  }
};
node *findkey(node *root, int k)
{
  if (!root)
    return nullptr;
  if (root->val == k)
    return root;
  node *foundnode = findkey(root->left, k);
  if (foundnode)
    return foundnode;
   foundnode = findkey(root->mid, k);
  if (foundnode)
     return foundnode;
  return findkey(root->right, k);
}
void import(node* root)
{
  int n;
  cin >> n;
  while (n--)
  {
    int op, key, val;
    cin >> op >> key >> val;
    node *temp = findkey(root, key);
    if (temp)
    {
      node *mover = new node(val);
      if (op == 0)
      {
        temp->left = mover;
      }
      if (op == 1)
      {
        temp->mid = mover;
      }
       if (op == 2)
      {
         temp->right = mover;
       }
    }
  }
}
void traversal(node *root)
{
  if (!root)
    return;
  traversal(root->left);
  traversal(root->mid);
  cout << root->val << endl;
  traversal(root->right);
}
int main()
{
  int r;
  cin >> r;
  node *root1 = new node(r);
  import(root1);
   traversal(root1);
  return 0;
}
