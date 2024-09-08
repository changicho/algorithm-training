#include <algorithm>
#include <climits>
#include <cmath>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
};

// use DFS
// time : O(N * M)
// space : O(N)
class Solution {
 private:
  bool answer = false;

  void search(ListNode* valNode, TreeNode* node) {
    if (!node || !valNode) {
      answer |= !valNode;
      return;
    }

    if (valNode->val != node->val) {
      return;
    }

    search(valNode->next, node->left);
    search(valNode->next, node->right);
  }

  void recursive(ListNode* valNode, TreeNode* node) {
    if (node->val == valNode->val) {
      search(valNode, node);
    }

    if (node->left) recursive(valNode, node->left);
    if (node->right) recursive(valNode, node->right);
  }

 public:
  bool isSubPath(ListNode* head, TreeNode* root) {
    recursive(head, root);

    return answer;
  }
};