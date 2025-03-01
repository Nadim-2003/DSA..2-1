#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct node{
    int val;
    node* left,*right;
    int height;

    node(int n){
        val=n;
        left=right=nullptr;
        height=1;
    }
};

int height(node* root){
    if(!root) return 0;
    return root->height;
}

int balance(node* root){

    return (height(root->left) - height(root->right));
}

node* rightRotation(node* root){

    node* child=root->left;
    node* childRight=child->right;

    child->right=root;
    root->left=childRight;

    root->height=1+max(height(root->left),height(root->right));
    child->height=1+max(height(child->left),height(child->right));

    return child;
}

node* leftRotation(node* root){

    node* child=root->right;
    node* childLeft=child->left;

    child->left=root;
    root->right=childLeft;

    root->height=1+max(height(root->left),height(root->right));
    child->height=1+max(height(child->left),height(child->right));

    return child;
}
node* insert(node* root,int key){
    
    if(!root){
        return new node(key);
    }

    if(root->val > key){
        root->left=insert(root->left,key);
    }else if(root->val < key){
        root->right=insert(root->right,key);
    }else{
        return root; //to remove duplicate
    }

    root->height=1+max(height(root->left),height(root->right)); //give here the height of node

    int Balance=balance(root);

    if(Balance > 1 && root->left->val > key)
    {
        return rightRotation(root);
    }
    else if(Balance < -1 && root->right->val < key)
    {
        return leftRotation(root);
    }
    else if(Balance >1 &&  root->left->val < key)
    {
            root->left=leftRotation(root->left);
            return rightRotation(root);
    }
    else if(Balance <-1 && root->right->val > key)
    {
           root->right=rightRotation(root->right);
          return leftRotation(root); 
    }
    return root;
}

void inoder(node* root){
    if(!root) return;

    inoder(root->left);
    cout<<root->val<<" ";
    inoder(root->right);
}

int main(){

  node* root=nullptr;

  root=insert(root,40);
  root=insert(root,10);
  root=insert(root,4);
  root=insert(root,23);
  root=insert(root,15);
  root=insert(root,19);
  root=insert(root,50);
  root=insert(root,42);

  inoder(root);
  cout<<endl;
    return 0;
}