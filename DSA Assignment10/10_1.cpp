// Binary Search Tree operations in C++

#include <iostream>
using namespace std;

class node {
public:
  int key;
  node *left, *right;
};

// Create a node
node *newNode(int item) {
  node* temp = new node();
  temp->key = item;
  temp->left = temp->right = NULL;
  return temp;
}

void inorder(node *root) {
  if (root != NULL) {
    inorder(root->left);

    cout << root->key << " -> ";

    inorder(root->right);
  }
}

// Insert a node
 node *insert( node *node, int key) {
  if (node == NULL) 
    return newNode(key);

  if (key < node->key)
    node->left = insert(node->left, key);
  else
    node->right = insert(node->right, key);

  return node;
}

int height(node* root){
    if(root==NULL)
        return -1;
    else{
        int l = height(root->left);
        int r = height(root->right);

        if(l>r)
            return l+1;
        else
            return r+1;
        
    }
}

node* levelOrderTraversal(node* root)
{
    int h = height(root);

    for(int i =0;i<h;i++)
    {

    }
}

int main() {
  node *root = NULL;
  root = insert(root, 8);
  root = insert(root, 3);
  root = insert(root, 1);
  root = insert(root, 6);
  root = insert(root, 7);
  root = insert(root, 10);
  root = insert(root, 14);
  root = insert(root, 4);

  cout << "Inorder traversal: ";
  inorder(root);
  cout<<"\n height of the BST is "<<height(root)<<endl;

}