#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Node {
 public:
  int val;
  vector<Node*> neighbors;
  Node() {
    val = 0;
    neighbors = vector<Node*>();
  }
  Node(int _val) {
    val = _val;
    neighbors = vector<Node*>();
  }
  Node(int _val, vector<Node*> _neighbors) {
    val = _val;
    neighbors = _neighbors;
  }
};

// use BFS

class Solution {
 public:
  Node* cloneGraph(Node* node) {
    if (!node) return NULL;
    unordered_map<Node*, Node*> copies;

    Node* copy = new Node(node->val, {});
    copies[node] = copy;

    queue<Node*> q;
    q.push(node);
    while (!q.empty()) {
      Node* cur = q.front();
      q.pop();

      for (Node* neighbor : cur->neighbors) {
        if (copies.find(neighbor) == copies.end()) {
          copies[neighbor] = new Node(neighbor->val, {});
          q.push(neighbor);
        }
        copies[cur]->neighbors.push_back(copies[neighbor]);
      }
    }
    return copy;
  }
};

// use DFS

class Solution {
 public:
  Node* cloneGraph(Node* node) {
    if (!node) return NULL;

    unordered_map<Node*, Node*> copies;
    Node* copy = recursive(copies, node);

    return copies[node];
  }

 private:
  Node* recursive(unordered_map<Node*, Node*>& copies, Node* node) {
    if (copies.find(node) == copies.end()) {
      copies[node] = new Node(node->val, {});

      for (Node* neighbor : node->neighbors) {
        copies[node]->neighbors.push_back(recursive(copies, neighbor));
      }
    }

    return copies[node];
  }
};