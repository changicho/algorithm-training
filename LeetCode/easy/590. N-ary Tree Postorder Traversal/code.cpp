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

// Definition for a Node.
class Node {
 public:
  int val;
  vector<Node*> children;

  Node() {}

  Node(int _val) { val = _val; }

  Node(int _val, vector<Node*> _children) {
    val = _val;
    children = _children;
  }
};

// use DFS
// time : O(N)
// space : O(N)
class Solution {
 public:
  vector<int> postorder(Node* root) {
    vector<int> answer;

    function<void(Node * root)> recursive = [&](Node* node) {
      for (Node* child : node->children) {
        recursive(child);
      }

      answer.push_back(node->val);
    };

    if (root) recursive(root);
    return answer;
  }
};