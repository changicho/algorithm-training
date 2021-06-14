#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

// use recursive

class Solution {
 public:
  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    int rootIndex = 0;
    for (int i = 0; i < inorder.size(); i++) m[inorder[i]] = i;

    return recursive(preorder, rootIndex, inorder, 0, inorder.size() - 1);
  }

 private:
  unordered_map<int, int> m;

  TreeNode* recursive(vector<int>& preorder, int& rootIndex, vector<int>& inorder, int left, int right) {
    if (rootIndex >= preorder.size() || left > right) return NULL;

    TreeNode* root = new TreeNode(preorder[rootIndex]);
    int pivot = find(inorder.begin() + left, inorder.begin() + right, preorder[rootIndex]) - inorder.begin();
    // int pivot = m[preorder[rootIndex]];
    rootIndex++;

    root->left = recursive(preorder, rootIndex, inorder, left, pivot - 1);
    root->right = recursive(preorder, rootIndex, inorder, pivot + 1, right);

    return root;
  }
};