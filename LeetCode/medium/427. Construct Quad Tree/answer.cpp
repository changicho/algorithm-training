#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Definition for a QuadTree node.
class Node {
 public:
  bool val;
  bool isLeaf;
  Node* topLeft;
  Node* topRight;
  Node* bottomLeft;
  Node* bottomRight;

  Node() {
    val = false;
    isLeaf = false;
    topLeft = NULL;
    topRight = NULL;
    bottomLeft = NULL;
    bottomRight = NULL;
  }

  Node(bool _val, bool _isLeaf) {
    val = _val;
    isLeaf = _isLeaf;
    topLeft = NULL;
    topRight = NULL;
    bottomLeft = NULL;
    bottomRight = NULL;
  }

  Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight,
       Node* _bottomLeft, Node* _bottomRight) {
    val = _val;
    isLeaf = _isLeaf;
    topLeft = _topLeft;
    topRight = _topRight;
    bottomLeft = _bottomLeft;
    bottomRight = _bottomRight;
  }
};

// use divide and conquer
// time : O(N^2 * log_2(N))
// space : O(log_2(N))
class Solution {
 private:
  vector<vector<int>> grid;

  bool isAreaSameValue(int x1, int y1, int length) {
    for (int x = x1; x < x1 + length; x++) {
      for (int y = y1; y < y1 + length; y++) {
        if (grid[x][y] != grid[x1][y1]) return false;
      }
    }
    return true;
  }

  Node* recursive(int x1, int y1, int length) {
    if (isAreaSameValue(x1, y1, length)) {
      return new Node(grid[x1][y1], true);
    }

    Node* root = new Node(false, false);

    int half = length / 2;

    root->topLeft = recursive(x1, y1, half);
    root->topRight = recursive(x1, y1 + half, half);
    root->bottomLeft = recursive(x1 + half, y1, half);
    root->bottomRight = recursive(x1 + half, y1 + half, half);

    return root;
  }

 public:
  Node* construct(vector<vector<int>>& grid) {
    int length = grid.size();
    this->grid = grid;

    return recursive(0, 0, length);
  }
};

// use divide and conquer (optimized)
// time : O(N^2)
// space : O(log_2(N))
class Solution {
 private:
  vector<vector<int>> grid;

  Node* recursive(int x1, int y1, int length) {
    // leaf case
    if (length == 1) {
      return new Node(grid[x1][y1], true);
    }

    int half = length / 2;

    Node* topLeft = recursive(x1, y1, half);
    Node* topRight = recursive(x1, y1 + half, half);
    Node* bottomLeft = recursive(x1 + half, y1, half);
    Node* bottomRight = recursive(x1 + half, y1 + half, half);

    if (topLeft->isLeaf && topRight->isLeaf && bottomLeft->isLeaf &&
        bottomRight->isLeaf && topLeft->val == topRight->val &&
        topRight->val == bottomLeft->val &&
        bottomLeft->val == bottomRight->val) {
      return new Node(topLeft->val, true);
    }

    return new Node(false, false, topLeft, topRight, bottomLeft, bottomRight);
  }

 public:
  Node* construct(vector<vector<int>>& grid) {
    int length = grid.size();
    this->grid = grid;

    return recursive(0, 0, length);
  }
};