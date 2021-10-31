#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use segment tree

class NumArray {
 private:
  struct SegmentTree {
    int size;
    vector<int> array;  // array value
    vector<int> tree;   // sumTree

    SegmentTree(vector<int> &nums) {
      size = nums.size();

      array = nums;
      tree.resize(size * 4);

      init(1, 0, size - 1);
    }

    int operation(int x, int y) {
      return x + y;
    }

    int init(int node, int left, int right) {
      // fit case
      if (left == right) {
        return tree[node] = array[left];
      }

      int mid = (left + right) / 2;

      int leftPart = init(node * 2, left, mid);
      int rightPart = init(node * 2 + 1, mid + 1, right);

      return tree[node] = operation(leftPart, rightPart);
    }

    void update(int node, int left, int right, int index, int value) {
      // out of bound
      if (index < left || index > right) return;

      // fit case
      if (left == right) {
        tree[node] = value;
        return;
      }

      int mid = (left + right) / 2;
      update(node * 2, left, mid, index, value);
      update(node * 2 + 1, mid + 1, right, index, value);

      int leftPart = tree[node * 2];
      int rightPart = tree[node * 2 + 1];
      tree[node] = operation(leftPart, rightPart);
    }

    void update(int index, int value) {
      update(1, 0, size - 1, index, value);
    }

    int query(int node, int left, int right, int queryLeft, int queryRight) {
      // out of bound
      if (queryRight < left || right < queryLeft) return 0;
      // queryRange is inner to range
      if (queryLeft <= left && right <= queryRight) return tree[node];

      int mid = (left + right) / 2;
      int leftPart = query(node * 2, left, mid, queryLeft, queryRight);
      int rightPart = query(node * 2 + 1, mid + 1, right, queryLeft, queryRight);

      return operation(leftPart, rightPart);
    }

    int query(int left, int right) {
      return query(1, 0, size - 1, left, right);
    }
  };

  SegmentTree *segmentTree;

 public:
  NumArray(vector<int> &nums) {
    segmentTree = new SegmentTree(nums);
  }

  void update(int index, int val) {
    segmentTree->update(index, val);
  }

  int sumRange(int left, int right) {
    return segmentTree->query(left, right);
  }
};
