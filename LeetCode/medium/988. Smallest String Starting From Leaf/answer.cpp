#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

// use DFS
// time : O(N^2)
// space : O(N)
class Solution {
 private:
  string answer = "";

  void recursive(TreeNode *node, vector<int> &path) {
    path.push_back(node->val);
    bool isLeaf = true;

    if (node->left) {
      isLeaf = false;
      recursive(node->left, path);
    }
    if (node->right) {
      isLeaf = false;
      recursive(node->right, path);
    }

    if (isLeaf) {
      string word = "";
      for (int &p : path) {
        word += p + 'a';
      }
      reverse(word.begin(), word.end());

      if (answer == "") {
        answer = word;
      } else {
        answer = min(answer, word);
      }
    }

    path.pop_back();
  }

 public:
  string smallestFromLeaf(TreeNode *root) {
    vector<int> path;

    recursive(root, path);

    return answer;
  }
};