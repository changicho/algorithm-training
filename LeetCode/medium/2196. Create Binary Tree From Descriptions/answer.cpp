#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
};

// use hash map
// time : O(N)
// space : O(N)
class Solution {
 public:
  TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
    TreeNode* root;

    unordered_map<int, TreeNode*> valToNode;
    unordered_map<int, int> parents;

    for (vector<int>& d : descriptions) {
      int p = d[0], c = d[1];
      bool isLeft = d[2] == 1;

      if (!valToNode[p]) valToNode[p] = new TreeNode(p);
      if (!valToNode[c]) valToNode[c] = new TreeNode(c);

      parents[c] = p;
      if (isLeft) {
        valToNode[p]->left = valToNode[c];
      } else {
        valToNode[p]->right = valToNode[c];
      }
    }

    for (auto it : valToNode) {
      if (parents.count(it.first) == 0) {
        root = valToNode[it.first];
        break;
      }
    }

    return root;
  }
};