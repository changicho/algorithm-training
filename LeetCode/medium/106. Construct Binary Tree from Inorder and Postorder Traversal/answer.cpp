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
  TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    int size = inorder.size();
    for (int i = 0; i < size; i++) {
      m[inorder[i]] = i;
    }
    int rootIdx = postorder.size() - 1;

    return build(inorder, postorder, rootIdx, 0, size - 1);
  }

 private:
  unordered_map<int, int> m;

  TreeNode* build(vector<int>& inorder, vector<int>& postorder, int& rootIdx, int left, int right) {
    if (left > right) return NULL;

    int pivot = m[postorder[rootIdx]];
    rootIdx--;
    TreeNode* node = new TreeNode(inorder[pivot]);

    node->right = build(inorder, postorder, rootIdx, pivot + 1, right);
    node->left = build(inorder, postorder, rootIdx, left, pivot - 1);

    return node;
  }
};