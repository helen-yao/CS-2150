#include "BinaryNode.h"
#include "BinarySearchTree.h"
#include <iostream>
#include <string>

using namespace std;

BinarySearchTree::BinarySearchTree() {
   root = new BinaryNode();
}

BinarySearchTree::~BinarySearchTree() {
    delete root;
    root = NULL;
}

void BinarySearchTree::insert(BinaryNode*& root, const string& x){
  if(root->value == "?")
    root->value = x;
 if(root->left == NULL && x < root->value){
    BinaryNode* temp = new BinaryNode();
    temp->value = x;
    root->left = temp;
    
  }
  else if(root->right == NULL && x > root->value){
    BinaryNode* temp = new BinaryNode();
    temp->value = x;
    root->right = temp;
  }
  else if(x < root->value){
    insert(root->left, x);
  }
  else if(x> root->value){
    insert(root->right, x);
  }
}
// insert finds a position for x in the tree and places it there.
void BinarySearchTree::insert(const string& x) {
    // YOUR IMPLEMENTATION GOES HERE
  insert(root, x);
}

// remove finds x's position in the tree and removes it.
void BinarySearchTree::remove(const string& x) {
  if(find(x) == true)
    remove(root, x);
}

// private helper for remove to allow recursion over different nodes. returns
// a BinaryNode* that is assigned to the original node.
BinaryNode* BinarySearchTree::remove(BinaryNode*& n, const string& x) {
    if (n == NULL) {
        return NULL;
    }

    // first look for x
    if (x == n->value) {
        // found
        if (n->left == NULL && n->right == NULL) {
            // no children
            // just delete it :)
            delete n;
            n = NULL;
            return NULL;
        } else if (n->left == NULL) {
            // single child (right)
            // remove current node and return right child node for parent
            BinaryNode* temp = n->right;
            n->right = NULL;
            delete n;
            n = NULL;
            return temp;
        } else if (n->right == NULL) {
            // single child (left)
            // remove current node and return left child node for parent
            BinaryNode* temp = n->left;
            n->left = NULL;
            delete n;
            n = NULL;
            return temp;
        } else {
            // two children
            // replace current node with right child node's minimum, then remove that node
            string value = min(n->right);
            n->value = value;
            n->right = remove(n->right, value);
        }
    } else if (x < n->value) {
        n->left = remove(n->left, x);
    } else {
        n->right = remove(n->right, x);
    }
    return n;
}

// pathTo finds x in the tree and returns a string representing the path it
// took to get there.
string BinarySearchTree::pathTo(BinaryNode*& root, const string& x, string result){
  if(x < root->value){
    result = result + root->value + " " + pathTo(root->left, x, result);
  }
  else if(x > root->value){
    result = result + root->value +" " + pathTo(root->right, x, result);
  }
  if(root-> value == x)
    result = result + x;
  return result;
}

string  BinarySearchTree::pathTo(const string& x)   {
    // YOUR IMPLEMENTATION GOES HERE
  string result = "";
  if(find(x) == false)
    return result;
  return pathTo(root, x, result);
}

bool BinarySearchTree::find(BinaryNode*& root, const string&x){
  if(root == NULL)
    return false;
  if(x == root->value)
    return true;
  else{
   if(x < root->value)
    return find(root->left, x);
  else
    return find(root->right, x);
  }
}
// find determines whether or not x exists in the tree.
bool BinarySearchTree::find(const string& x){
    // YOUR IMPLEMENTATION GOES HERE
  return find(root, x);
}

int BinarySearchTree::numNodes(BinaryNode*& root){
  if(root == NULL)
    return 0;
  else
    return numNodes(root->right)+numNodes(root->left)+1;
}

// numNodes returns the total number of nodes in the tree.
int BinarySearchTree::numNodes() {
    // YOUR IMPLEMENTATION GOES HERE
  return numNodes(root);
}

// min finds the string with the smallest value in a subtree.
string BinarySearchTree::min(BinaryNode* node) const {
    // go to bottom-left node
    if (node->left == NULL) {
        return node->value;
    }
    return min(node->left);
}

// Helper function to print branches of the binary tree
// You do not need to know how this function works.
void showTrunks(Trunk* p) {
    if (p == NULL) return;
    showTrunks(p->prev);
    cout << p->str;
}

void BinarySearchTree::printTree() {
    printTree(root, NULL, false);
}

// Recursive function to print binary tree
// It uses inorder traversal
void BinarySearchTree::printTree(BinaryNode* root, Trunk* prev, bool isRight) {
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

