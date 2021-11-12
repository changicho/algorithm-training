#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
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

// use BFS

class Solution {
 public:
  vector<vector<int>> levelOrder(Node* root) {
    queue<Node*> q;
    vector<vector<int>> answer;

    if (root) q.push(root);

    while (!q.empty()) {
      int size = q.size();

      vector<int> line;
      while (size--) {
        Node* cur = q.front();
        q.pop();

        line.push_back(cur->val);

        for (Node* child : cur->children) {
          q.push(child);
        }
      }

      answer.push_back(line);
    }

    return answer;
  }
};