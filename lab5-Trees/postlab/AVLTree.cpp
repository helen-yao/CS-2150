#include "AVLNode.h"
#include "AVLTree.h"
#include <iostream>
#include <string>
using namespace std;

AVLTree::AVLTree() {
   root = new AVLNode();
}

AVLTree::~AVLTree() {
    delete root;
    root = NULL;
}

// insert finds a position for x in the tree and places it there, rebalancing
// as necessary.
void AVLTree::insert(const string& x) {
    // YOUR IMPLEMENTATION GOES HERE
  insert(root,x);
}

void AVLTree::insert(AVLNode*& node, const string& x){
  if(node->value == "?")
    node->value = x;
  if(node->left == NULL && x < node->value){
    AVLNode* temp = new AVLNode();
    temp->value = x;
    node->left = temp;
  }
  else if(node->right == NULL && x >node->value){
    AVLNode* temp = new AVLNode();
    temp->value = x;
    node->right = temp;
    
  }
  else if(x < node->value){
    insert(node->left,x);
  }
  else if(x > node->value){
    insert(node->right, x);
  }
  node->height = 1 + max(height(node->left), height(node->right));
  balance(node);
}

// remove finds x's position in the tree and removes it, rebalancing as
// necessary.
void AVLTree::remove(const string& x) {
  if(find(x) == true)
     remove(root, x);
}

// pathTo finds x in the tree and returns a string representing the path it
// took to get there.
string AVLTree::pathTo(const string& x) {
    // YOUR IMPLEMENTATION GOES HERE
  string result = "";
  if(find(x) == false)
    return result;
  return pathTo(root,x,result);
}

string AVLTree::pathTo(AVLNode*& node, const string& x, string result){
  if(x<node->value)
    result = result + node->value + " " + pathTo(node->left, x, result);
  else if(x > node->value)
    result = result + node->value + " " + pathTo(node->right, x, result);
  if(node->value == x)
    result = result + x;
  
  return result;
}

// find determines whether or not x exists in the tree.
bool AVLTree::find(const string& x)  {
    // YOUR IMPLEMENTATION GOES HERE
  return find(root, x);
}

bool AVLTree::find(AVLNode*& node, const string&x){
  if(node == NULL)
    return false;
  if(x == node->value)
    return true;
  else{
    if(x < node->value)
      return find(node->left,x);
    else
      return find(node->right, x);
  }
}

// numNodes returns the total number of nodes in the tree.
int AVLTree::numNodes()  {
    // YOUR IMPLEMENTATION GOES HERE
  return numNodes(root);
}

int AVLTree::numNodes(AVLNode*& node){
  if(node == NULL)
    return 0;
  else
    return numNodes(node->right)+numNodes(node->left)+1;
}

// balance makes sure that the subtree with root n maintains the AVL tree
// property, namely that the balance factor of n is either -1, 0, or 1.
void AVLTree::balance(AVLNode*& n) {
    // YOUR IMPLEMENTATION GOES HERE
  if(height(n->right)-height(n->left) ==2){
    if(height(n->right)-height(n->left)<0)
     rotateRight(n->right);
  
    rotateLeft(n);
  }
    else if(height(n->right)-height(n->left) ==-2){
       if(height(n->right)-height(n->left)>0)
          rotateLeft(n->left);
       
     rotateRight(n);
    }
}

// rotateLeft performs a single rotation on node n with its right child.
AVLNode* AVLTree::rotateLeft(AVLNode*& n) {
    // YOUR IMPLEMENTATION GOES HERE
   AVLNode* temp = n->right;
  n->right= temp->left;
  temp->left = n;
  n->height = 1 + max(height(n->left), height(n->right));
  n = temp;
  return temp;
}

// rotateRight performs a single rotation on node n with its left child.
AVLNode* AVLTree::rotateRight(AVLNode*& n) {
    // YOUR IMPLEMENTATION GOES HERE
   AVLNode* temp = n->left;
  n->left  = temp->right;
  temp->right = n;
   n->height = 1 + max(height(n->left), height(n->right));
   n = temp;
  return temp;
}

// private helper for remove to allow recursion over different nodes.
// Returns an AVLNode* that is assigned to the original node.
AVLNode* AVLTree::remove(AVLNode*& n, const string& x) {
    if (n == NULL) {
        return NULL;
    }

    // first look for x
    if (x == n->value) {
        // found
        if (n->left == NULL && n->right == NULL) {
            // no children
            delete n;
            n = NULL;
            return NULL;
        } else if (n->left == NULL) {
            // Single child (left)
            AVLNode* temp = n->right;
            n->right = NULL;
            delete n;
            n = NULL;
            return temp;
        } else if (n->right == NULL) {
            // Single child (right)
            AVLNode* temp = n->left;
            n->left = NULL;
            delete n;
            n = NULL;
            return temp;
        } else {
            // two children -- tree may become unbalanced after deleting n
            string sr = min(n->right);
            n->value = sr;
            n->right = remove(n->right, sr);
        }
    } else if (x < n->value) {
        n->left = remove(n->left, x);
    } else {
        n->right = remove(n->right, x);
    }

    // Recalculate heights and balance this subtree
    n->height = 1 + max(height(n->left), height(n->right));
    balance(n);

    return n;
}

// min finds the string with the smallest value in a subtree.
string AVLTree::min(AVLNode* node) const {
    // go to bottom-left node
    if (node->left == NULL) {
        return node->value;
    }
    return min(node->left);
}

// height returns the value of the height field in a node.
// If the node is null, it returns -1.
int AVLTree::height(AVLNode* node)  {
  if (node == NULL)
    return -1;
  int leftHeight = height(node->left);
  int rightHeight = height(node->right);
  return max(leftHeight, rightHeight)+1;
}

int AVLTree::height(AVLNode*& node, const string& x, int count){
  if(node == NULL)
    return -1;
  if(node->value == x)
    return 0;
  else if(node->value < x)
    return height(node->left, x, count+1);
  else if(node->value > x)
    return height(node->right, x, count+1);
}

// max returns the greater of two integers.
int max(int a, int b) {

  if (a > b) {
        return a;
    }
    return b;
}

// Helper function to print branches of the binary tree
// You do not need to know how this function works.
void showTrunks(Trunk* p) {
    if (p == NULL) return;
    showTrunks(p->prev);
    cout << p->str;
}

// Recursive function to print binary tree
// It uses inorder traversal
void AVLTree::printTree(AVLNode* root, Trunk* prev, bool isRight) {
    if (root == NULL) return;

    string prev_str = "    ";
    Trunk* trunk = new Trunk(prev, prev_str);

    printTree(root->right, trunk, true);

    if (!prev)
        trunk->str = "---";
    else if (isRight) {
        trunk->str = ".---";
        prev_str = "   |";
    } else {
        trunk->str = "`---";
        prev->str = prev_str;
    }

    showTrunks(trunk);
    cout << root->value << endl;

    if (prev) prev->str = prev_str;
    trunk->str = "   |";

    printTree(root->left, trunk, false);

    delete trunk;
}

void AVLTree::printTree() {
    printTree(root, NULL, false);
}
