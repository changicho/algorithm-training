#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Node {
  int data;
  Node *left, *right;
};

void recursive(Node *node, long long number, long long &leafVal) {
  if (!node) {
    return;
  }
  long long data = node->data;

  if (!node->left && !node->right) {
    leafVal += number * 10 + data;
    return;
  }

  if (node->left) {
    recursive(node->left, number * 10 + data, leafVal);
  }
  if (node->right) {
    recursive(node->right, number * 10 + data, leafVal);
  }
}

long long treePathsSum(Node *root) {
  long long leafVal = 0;

  recursive(root, 0, leafVal);

  return leafVal;
}