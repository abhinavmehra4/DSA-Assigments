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

node* insert_array(node* root, int x[],int z)
{
    int j = z-1;
    for(int i=0;i<j;i++)
    {
        root = insert(root,x[i]);
    }

    return root;
}

int main() {
  node *root = NULL;

  int x[] = {1,2,3,4,5,6,7};
  int z = sizeof(x)/sizeof(x[0]);

  root = insert_array(root,x,z);

  cout << "Inorder traversal: ";
  inorder(root);

}