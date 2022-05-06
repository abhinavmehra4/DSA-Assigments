// Binary Search Tree operations in C++

#include <iostream>
#include <string>
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

string search(node* root,int number)
{
    if(root==NULL)
        return "NOT PRESENT";
    if(number==root->key)
        return "PRESENT";
    if(number<root->key)
        return search(root->left,number);
    if(number>root->key)
        return search(root->right,number);

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

  cout<<"\nWhich element do you want to search\n";
  int x;
  cin>>x;

  cout<<search(root,x)<<endl;

}